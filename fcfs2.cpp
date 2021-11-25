#include <iostream>
using namespace std;

void findCompletionTime(int ct[], int n, int bt[], int at[])
{
    // the completion time for the first process
    // will be the burst_time for it
    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        // When the process arives after the completion of the
        // previous process
        if (ct[i - 1] < at[i])
        {
            ct[i] = ct[i - 1] + bt[i] + (at[i] - ct[i - 1]);
        }
        // The next process is already in the ready queue
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }
}

void turnAroundTime(int tat[], int ct[], int at[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // Turn Around Time = completion time - arrival time
        tat[i] = ct[i] - at[i];
    }
}

void findWaitingTime(int wt[], int tat[], int bt[], int n)
{
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }
}

void findAvgTime(int process[], int at[], int bt[], int n)
{
    int total_tat = 0, total_wt = 0;
    int wt[n], tat[n], ct[n];
    
    //function to find completion time of all processes
    findCompletionTime(ct, n, bt, at);
    
    //function to find turn around time of all processes
    turnAroundTime(tat, ct, at, n);

    //function to find waiting time of all processes
    findWaitingTime(wt, tat, bt, n);

    // Display process along with all details
    printf("P-id | Arrival | Burst| Completion | Turn-around | Waiting \n");

    // Calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("  %d", (i + 1));
        printf("  \t %d", at[i]);
        printf("  \t   %d", bt[i]);
        printf("  \t   %d", ct[i]);
        printf("  \t\t  %d", tat[i]);
        printf("  \t\t%d\n", wt[i]);
    }

    float s = (float)total_wt / (float)n;
    float t = (float)total_tat / (float)n;

    printf("Average waiting time= %.2f\n", s);
    printf("Average turn around time= %.2f\n", t);
}

int main()
{
    //process id's
    int process[] = {1, 2, 3, 4};
    int n = sizeof process / sizeof process[0];

    //Arrival time of all processes
    int arrival_time[] = {0, 1, 5, 6};
    
    //Burst time of all process
    int burst_time[] = {2, 2, 3, 4};

    findAvgTime(process, arrival_time, burst_time, n);

    return 0;
}