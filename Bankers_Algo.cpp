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

    // int alloc[proc][res] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

    // int max[proc][res] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};

    // int avail[res] = {3, 3, 2};

    int need[proc][res];
    for (int i = 0; i < proc; i++)
    {
        for (int j = 0; j < res; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int finish[proc] = {0};
    int safe[proc];
    int count = 0;

    for (int x = 0; x < proc; x++)
    {
        for (int i = 0; i < proc; i++)
        {
            if (finish[i] == 0)
            {
                int j = 0;
                for (j = 0; j < res; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        break;
                    }
                }
                if (j == res)
                {
                    for (int k = 0; k < res; k++)
                    {
                        avail[k] += alloc[i][k];
                    }
                    finish[i] = 1;
                    safe[count++] = i + 1;
                }
            }
        }
    }

    // check safe or not
    int flag = 0;
    for (int i = 0; i < proc; i++)
    {
        if (finish[i] == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        cout << "Safe Sequence is: ";
        for (int i = 0; i < proc; i++)
        {
            cout << "P" << safe[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Not Safe" << endl;
    }
}