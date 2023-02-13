#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

typedef struct Process
{
    int id;
    int burstTime;
    int arrivalTime;
    int remainingTime;
    int waitingTime;
    int turnAroundTime;
    bool completed;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum)
{
    int currentTime = 0;
    int remainingProcesses = n;
    while (remainingProcesses > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (processes[i].completed == false && processes[i].arrivalTime <= currentTime)
            {
                if (processes[i].remainingTime > quantum)
                {
                    currentTime += quantum;
                    processes[i].remainingTime -= quantum;
                }
                else
                {
                    currentTime += processes[i].remainingTime;
                    processes[i].waitingTime = currentTime - processes[i].burstTime;
                    processes[i].turnAroundTime = currentTime - processes[i].arrivalTime;
                    processes[i].completed = true;
                    remainingProcesses--;
                }
            }
        }
    }
}

int compareProcesses(const void* a, const void* b)
{
    Process* p1 = (Process*)a;
    Process* p2 = (Process*)b;
    return p1->arrivalTime - p2->arrivalTime;
}

int main()
{
    int n, quantum;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter the time quantum: ";
    cin>>quantum;
    Process processes[20];

    cout<<"Enter the burst time and arrival time of each process: "<<endl;
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        scanf("%d%d", &processes[i].burstTime, &processes[i].arrivalTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].completed = false;
    }

    qsort(processes, n, sizeof(Process), compareProcesses);

    calculateWaitingTime(processes, n, quantum);
    cout<<"Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time"<<endl;
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
        cout<<processes[i].id<<"\t\t"<<processes[i].burstTime<<"\t\t"<<processes[i].arrivalTime<<"\t\t"<<processes[i].waitingTime<<"\t\t"<<processes[i].turnAroundTime<<endl;
    }
}