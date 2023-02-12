#include <iostream>
using namespace std;
int main()
{
    int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
    cout << "Enter total number of processes(maximum 20):";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "\np[" << i + 1 << "]: ";
        //burst time
        cin >> bt[i];
    }

    //waiting time for first process is 0
    wt[0] = 0;

    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
    }

    for (i = 0; i < n; i++)
    {
        //turn around time = burst time + waiting time
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
    }

    //average waiting time and turn around time
    avwt /= i;
    avtat /= i;

    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurn Time" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "\np[" << i + 1 << "]\t\t";
        // burst time , waiting time, turn around time
        cout << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }
    
    cout << "\nAverage waiting time: " << avwt;
    cout << "\nAverage turn around time: " << avtat << endl;

    return 0;
}
