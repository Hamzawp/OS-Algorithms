#include <iostream>
#include <algorithm>
using namespace std;

struct Process
{
    int pid;
    int bt;
    int tat;
    int wt;
    int priority;
};

bool compare(Process P1, Process P2)
{
    return P1.priority < P2.priority;
}

void findWaitingTime(Process processes[], int n)
{
    sort(processes, processes + n, compare);
    processes[0].wt = 0;
    for (int i = 1; i < n; i++)
        processes[i].wt = processes[i - 1].wt + processes[i - 1].bt;
}
void findTurnaroundTime(Process processes[], int n)
{
    for (int i = 0; i < n; i++)
        processes[i].tat = processes[i].bt + processes[i].wt;
}

void findAvgTime(Process processes[], int n)
{
    int awt = 0, atat = 0;
    findWaitingTime(processes, n);
    findTurnaroundTime(processes, n);
    cout << "Process\t\tPriority\tBurst-Time\tWaiting-Time\tTurnAround-Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].pid << "\t\t" << processes[i].priority << "\t\t" << processes[i].bt << "\t\t" << processes[i].wt << "\t\t" << processes[i].tat << endl;
        awt += processes[i].wt;
        atat += processes[i].tat;
    }
    cout << "Average Waiting Time: " << (float)awt / (float)n << endl;
    cout << "Average Turn-Around Time: " << (float)atat / (float)n << endl;
}

int main()
{
    int n;
    cout << "Enter number of process: ";
    cin >> n;
    Process processes[n];
    cout << "Enter burst time and priority for each process:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processes[i].bt;
        cin >> processes[i].priority;
        processes[i].pid = i + 1;
        processes[i].wt = 0;
        processes[i].tat = 0;
    }
    findAvgTime(processes, n);
    return 0;
}