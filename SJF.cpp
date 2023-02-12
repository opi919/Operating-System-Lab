#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j, flag, prev_wt = 0;
    vector<vector<int>> vt;
    vt.resize(20);
    cout << "Enter total number of processes(maximum 20): ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "\np[" << i + 1 << "]: ";
        // burst time
        cin >> bt[i + 1];
        // push the process number in burst time index
        vt[bt[i + 1]].push_back(i + 1);
    }

    // Sorting the vector
    sort(vt[0].begin(), vt[0].end());

    flag = 0;
    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurn Around" << endl;
    for (i = 0; i < vt.size(); i++)
    {
        for (j = 0; j < vt[i].size(); j++)
            if (!vt[i].empty())
            {
                flag++;
                // process number, burst time
                cout << "\np[" << vt[i][j] << "]\t\t" << bt[vt[i][j]] << "\t\t";
                if (flag == 1)
                {
                    // waiting time 0 for first process
                    wt[vt[i][j]] = 0;
                    tat[vt[i][j]] = bt[vt[i][j]];
                    prev_wt = vt[i][j];
                }
                else
                {
                    // waiting time = previous waiting time + previous burst time
                    wt[vt[i][j]] = wt[prev_wt] + bt[prev_wt];
                    // turn around time = burst time + waiting time
                    tat[vt[i][j]] = bt[vt[i][j]] + wt[vt[i][j]];
                    prev_wt = vt[i][j];
                }
                cout << wt[vt[i][j]] << "\t\t" << tat[vt[i][j]];
            }
    }

    // average waiting time and turn around time
    for (i = 0; i < n; i++)
    {
        avwt += wt[i + 1];
        avtat += tat[i + 1];
    }
    avwt /= n;
    avtat /= n;
    cout << "\nAverage Waiting Time: " << avwt;
    cout << "\nAverage Turn Around Time: " << avtat << endl;

    return 0;
}