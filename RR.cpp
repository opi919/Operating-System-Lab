#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

typedef struct Process {
    int id;
    int burstTime;
    int arrivalTime;
    int remainingTime;
    int waitingTime;
    int turnAroundTime;
    bool completed;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int currentTime = 0;
    int remainingProcesses = n;
    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].completed == false && processes[i].arrivalTime <= currentTime) {
                if (processes[i].remainingTime > quantum) {
                    currentTime += quantum;
                    processes[i].remainingTime -= quantum;
                } else {
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

void sortProcessesByArrivalTime(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (processes[j].arrivalTime < processes[minIndex].arrivalTime) {
                minIndex = j;
            }
        }
        Process temp = processes[i];
        processes[i] = processes[minIndex];
        processes[minIndex] = temp;
    }
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    Process processes[MAX_PROCESSES];
    printf("Enter the burst time and arrival time of each process: \n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        scanf("%d%d", &processes[i].burstTime, &processes[i].arrivalTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].completed = false;
    }
    sortProcessesByArrivalTime(processes, n);
    calculateWaitingTime(processes, n, quantum);
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, processes[i].arrivalTime, processes[i].waitingTime, processes[i].turnAroundTime);
    }
}