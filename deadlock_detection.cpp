#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int proc, res;
    cout << "Enter the number of processes: ";
    cin >> proc;
    cout << "Enter the number of resources: ";
    cin >> res;

    int alloc[proc][res];
    int max[proc][res];
    int avail[res];
    int finish[proc] = {0};
    int need[proc][res];

    cout << "Enter the allocation matrix: " << endl;
    for (int i = 0; i < proc; i++)
    {
        for (int j = 0; j < res; j++)
        {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter the max matrix: " << endl;
    for (int i = 0; i < proc; i++)
    {
        for (int j = 0; j < res; j++)
        {
            cin >> max[i][j];
        }
    }

    cout << "Enter the available matrix: " << endl;
    for (int i = 0; i < res; i++)
    {
        cin >> avail[i];
    }

    // Calculate the need matrix
    for (int i = 0; i < proc; i++)
    {
        for (int j = 0; j < res; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Detect deadlock
    bool deadlocked = true;
    while (deadlocked)
    {
        deadlocked = false;

        for (int i = 0; i < proc; i++)
        {
            if (finish[i] == 0)
            {
                bool canExecute = true;
                for (int j = 0; j < res; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute)
                {
                    deadlocked = false;
                    finish[i] = 1;
                    for (int j = 0; j < res; j++)
                    {
                        avail[j] += alloc[i][j];
                    }
                }
            }
        }
    }

    // Output deadlock status
    bool isDeadlocked = false;
    for (int i = 0; i < proc; i++)
    {
        if (finish[i] == 0)
        {
            isDeadlocked = true;
            break;
        }
    }

    if (isDeadlocked)
    {
        cout << "The system is deadlocked!" << endl;
    }
    else
    {
        cout << "The system is not deadlocked!" << endl;
    }
}
 