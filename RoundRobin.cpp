#include <iostream>
using namespace std;

int main() {
    
  float n, quantum, avwt = 0, avtat = 0;
  float pid[50], bt[50], at[50], rem_time[50], comp_time[50];
  float wt[50], tat[50];

  cout << "Enter total number of processes: ";
  cin >> n;

  cout << "Enter time quantum: ";
  cin >> quantum;

  cout << "\nEnter the arrival time and burst time for each process: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "Process " << i + 1 << ":\n";
    pid[i] = i + 1;
    cout << "\tArrival time: ";
    cin >> at[i];
    cout << "\tBurst time: ";
    cin >> bt[i];
    rem_time[i] = bt[i];
    wt[i] = tat[i] = 0;
  }

  int curr_time = 0, total_rem_time = n;
  while (total_rem_time > 0) {
    for (int i = 0; i < n; i++) {
      if (rem_time[i] > 0) {
        if (rem_time[i] <= quantum) {
          curr_time += rem_time[i];
          rem_time[i] = 0;
          total_rem_time--;
          comp_time[i] = curr_time;
        } else {
          curr_time += quantum;
          rem_time[i] -= quantum;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    tat[i] = comp_time[i] - at[i];
    wt[i] = tat[i] - bt[i];
    avwt += wt[i];
    avtat += tat[i];
  }

  avwt /= n;
  avtat /= n;

  cout
      << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
  for (int i = 0; i < n; i++) {
    cout << "P" << pid[i] << "\t\t" << at[i] << "\t\t\t\t" << bt[i] << "\t\t\t"
         << wt[i] << "\t\t\t\t" << tat[i] << endl;
  }

  cout << "\nAverage Waiting Time: " << avwt;
  cout << "\nAverage Turnaround Time: " << avtat;

  return 0;
}