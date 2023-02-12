#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    Process processes[20];
    printf("Enter the burst time and arrival time of each process: \n");
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        scanf("%d%d", &processes[i].burstTime, &processes[i].arrivalTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].completed = false;
    }

    qsort(processes, n, sizeof(Process), compareProcesses);

    calculateWaitingTime(processes, n, quantum);
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, processes[i].arrivalTime, processes[i].waitingTime, processes[i].turnAroundTime);
    }
}