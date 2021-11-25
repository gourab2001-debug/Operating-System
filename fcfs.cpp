#include <iostream>
using namespace std;

void findWaitingTime(int bt[], int wt[], int n, int process[])
{
    //waiting time for first process is 0;
    wt[0] = 0;

    //calculating waiting time
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

//function to  calculate turn arround time
void findTurnAroundTime(int process[], int n, int bt[], int wt[], int tat[])
{
    //calculating turnarround time by adding
    // bt[i]+wt[i]

    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
//function to calculate the average time
void findAvgtime(int process[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    
    //function to find wainting  process of all process
    findWaitingTime(bt, wt, n, process);

    //function to find turn around time for all process
    findTurnAroundTime(process, n, bt, wt, tat);
    
    // Display process along with all details
    printf("    process | Burst-time| waiting-time | Turn-around-time\n");
    
    // Calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("      %d", (i + 1));
        printf("  \t%d", bt[i]);
        printf("     \t\t%d", wt[i]);
        printf("   \t\t%d\n", tat[i]);
    }

    int s = (float)total_wt / (float)n;
    int t = (float)total_wt / (float)n;
    printf("Average waiting time= %d", s);
    printf("\n");
    printf("Average turn around time= %d\n", t);
}
int main()
{
    //process id's
    int process[] = {1, 2, 3};
    int n = sizeof process / sizeof process[0];
    //Burst time of all process
    int burst_time[] = {10, 5, 8};
    findAvgtime(process, n, burst_time);
    return 0;
}