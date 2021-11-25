#include <iostream>
using namespace std;

/* 
Sorting is not ncessary but it will make the process easier 
because in "Shortest Job First" the process with similar or 
dissimilar arrival time and similar or disimilar burst time 
will be treated differently, the ones with fast arrival time 
and short burst time will be done first 
*/
void sort_2d_array(int arr[][3], int n)
{
    for(int i = 0; i < n ; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            // swap all values from low to higher values of arrival time
            if(arr[i][1] > arr[j][1])
            {
                for(int x = 0; x < 3; x++)
                {
                    int temp = arr[i][x];
                    arr[i][x] = arr[j][x];
                    arr[j][x] = temp;
                }
            }
            // swap all values with same arrival time but shorter burst time
            if(arr[i][1] == arr[j][1] && arr[i][2] > arr[j][2])
            {
                for(int x = 0; x < 3; x++)
                {
                    int temp = arr[i][x];
                    arr[i][x] = arr[j][x];
                    arr[j][x] = temp;
                }
            }
        }
    }  
}

void findCompletionTime(int process[][3], int ct[], int n)
{
    // completion time = Arrival time + Burst time
    ct[0] = process[0][1] + process[0][2];
    for(int i = 1; i < n; i++)
    {
        ct[i] = ct[i-1] + process[i][2];
    }
}

void findTurnAroundTime(int process[][3], int tat[], int ct[], int n)
{
    for(int i = 0; i< n; i++)
    {
        // Turn Around time = Completion time - Arrival Time 
        tat[i] = ct[i] - process[i][1];
    }
}

void findWaitingTime(int process[][3], int wt[], int tat[], int n)
{
    for(int i = 0 ; i < n; i++)
    {
        // Waiting time = TurnAround time - Burst Time
        wt[i] = tat[i] - process[i][2];
    }
}

void findAvgTime(int process[][3], int n)
{
    int total_tat = 0, total_wt = 0;
    int wt[n], tat[n], ct[n];

    findCompletionTime(process, ct, n);
    findTurnAroundTime(process, tat, ct, n);
    findWaitingTime(process, wt, tat, n);

    cout << "P-id\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
    {
        cout << "P" << process[i][0] << "\t" << process[i][1]<< "\t" << process[i][2]<< "\t";
        cout << ct[i]<< "\t" << tat[i]<< "\t" << wt[i] << endl;

        total_tat += tat[i];
        total_wt += wt[i];
    }

    float avg_tat = total_tat/n;
    float avg_wt = total_wt/n;

    cout << "Average Turn Around Time = " << avg_tat << endl;
    cout << "Average Waiting Time = " << avg_wt << endl;

}
int main()
{
    // Process Id
    int process[][3] = {{1, 1, 3}, { 2, 2, 4}, {3, 1, 2}, {4, 4, 4}};
    int no_of_processes = 4;

    //Sorting the processes acording to arrival and burst time
    sort_2d_array(process, no_of_processes);

    findAvgTime(process, no_of_processes);

    return 0;
}