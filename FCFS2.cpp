#include<bits/stdc++.h>


using namespace std;

struct Process {
    int processId;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

int compareProc(const void* a,const void* b){
    struct Process* p1 = (struct Process*)a;
    struct Process* p2 = (struct Process*)b;
    // Sort by burst time
    return p1->processId - p2->processId;
}

void calculateWaitingTime(struct Process* proc, int n){
    proc[0].waitingTime = 0;
    for(int i=1;i<n;i++){
        proc[i].waitingTime = proc[i-1].burstTime + proc[i-1].waitingTime;
    }
}

void calculateTurnaroundTime(struct Process* proc, int n){
    for(int i=0;i<n;i++){
        proc[i].turnaroundTime = proc[i].burstTime + proc[i].waitingTime;
    }
}

int main(){
    Process proc[20];
    int n,i;
        cout << "Enter total number of processes(maximum 20):";
    cin >> n;

    for(i=0;i<n;i++){
        cout << "\np[" << i + 1 << "]: ";
        cin>>proc[i].processId;
        //burst time
        cin >> proc[i].burstTime;
    }

    qsort(proc,n, sizeof(struct Process),compareProc);

    calculateWaitingTime(proc,n);

    calculateTurnaroundTime(proc,n);

    cout<<"Process\t\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;

    for(i=0;i<n;i++){
        cout<<"p["<<proc[i].processId<<"]\t\t"<<proc[i].burstTime<<"\t\t"<<proc[i].waitingTime<<"\t\t"<<proc[i].turnaroundTime<<endl;
    }
}