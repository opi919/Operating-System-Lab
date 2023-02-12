#include<bits/stdc++.h>
#include<stdlib.h>

using namespace std;

struct Process {
    int processId;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

int compareProcesses(const void* a, const void* b) {
    struct Process* p1 = (struct Process*)a;
    struct Process* p2 = (struct Process*)b;
    // Sort by burst time
    return p1->burstTime - p2->burstTime;
}

void calculateWaitingTime(struct Process* processes, int n) {
    int i;
    processes[0].waitingTime = 0;
    for (i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i-1].burstTime + processes[i-1].waitingTime;
    }
}

void calculateTurnaroundTime(struct Process* processes, int n) {
    int i;
    for (i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}


int main(){
    int n ,i ;
    Process processes[20];
        cout << "Enter total number of processes(maximum 20):";
        cin>>n;

        for(i=0;i<n;i++)
        {
            cout << "\np[" << i + 1 << "]: ";
            processes[i].processId = i+1;
            // burst time
            cin >> processes[i].burstTime;
        }

    qsort(processes, n, sizeof(struct Process), compareProcesses);

    calculateWaitingTime(processes, n);

    calculateTurnaroundTime(processes, n);

    cout<<"Process\t\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"p["<<processes[i].processId<<"]\t\t"<<processes[i].burstTime<<"\t\t"<<processes[i].waitingTime<<"\t\t"<<processes[i].turnaroundTime<<endl;
    }

}