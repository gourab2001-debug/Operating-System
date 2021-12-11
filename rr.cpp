// Program for Round Robin Scheduling
/*
1- Create an array rem_bt[] to keep track of remaining
   burst time of processes. This array is initially a
   copy of bt[] (burst times array)
2- Create another array wt[] to store waiting times
   of processes. Initialize this array as 0.
3- Initialize time : t = 0
4- Keep traversing the all processes while all processes
   are not done. Do following for i'th process if it is
   not done yet.
    a- If rem_bt[i] > quantum
       (i)  t = t + quantum
       (ii) rem_bt[i] -= quantum;
    c- Else // Last cycle for this process
       (i)  t = t + rem_bt[i];
       (ii) wt[i] = t - bt[i]
       (ii) rem_bt[i] = 0; // This process is over
Once we have waiting times, we can compute turn around time tat[i] of a process as sum of waiting and burst times, i.e., wt[i] + bt[i]
*/
#include <iostream>
using namespace std;

// Returns 1 when all the processes are done executing
int isdone(int rem_bt[], int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        flag += rem_bt[i];
    }
    if (flag == 0)
        return 1;
    return 0;
}
void findWaitingTime(int n, int bt[], int wt[], int quantum)
{
    // Rem_bt stores the remaining burst time of the processes
    int rem_bt[n], t = 0;
    // Initializing the rem_bt with the values of bt
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }
    // The while loop will run till all the process is done
    while (!isdone(rem_bt, n))
    {
        for (int i = 0; i < n; i++)
        {
            // For the processes not being completed
            if (rem_bt[i] != 0)
            {
                if (rem_bt[i] > quantum)
                {
                    t = t + quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0; // This process is over
                }
            }
        }
    }
}
void findTurnAroundTime(int wt[], int bt[], int n, int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }
}
void findAvgTime(int processes[], int n, int bt[], int quantum)
{
    // Initializing the waiting time to zero
    int wt[n] = {};
    int tat[n];
    int total_tat = 0, total_wt = 0;
    findWaitingTime(n, bt, wt, quantum);
    findTurnAroundTime(wt, bt, n, tat);

    cout << "PNo\t"
         << "AT\t"
         << "BT\t"
         << "TAT\t"
         << "WT\t" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << 0 << "\t" << bt[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
        total_tat += tat[i];
        total_wt += wt[i];
    }

    int avg_tat = (float)total_tat / (float)n;
    int avg_wt = (float)total_wt / (float)n;

    cout << " Average Waiting Time = " << avg_wt << endl;
    cout << " Average Turn Around Time = " << avg_tat << endl;
}

int main()
{
    // process id's
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];

    // Burst time of all processes
    int burst_time[] = {10, 5, 8};

    // Time quantum
    int quantum = 2;
    findAvgTime(processes, n, burst_time, quantum);
    return 0;
}