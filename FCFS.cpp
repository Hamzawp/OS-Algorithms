#include <iostream>

using namespace std;
int main()
{
    int n, wt[100], tat[100], b[100], awt = 0, atat = 0;
    cout << "Enter the number of process: ";
    cin >> n;
    cout << "\nEnter process burst time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]: ";
        cin >> b[i];
        wt[i] = 0;
    }
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + b[i - 1];
    cout << "\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time";
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + b[i];
        awt += wt[i];
        atat += tat[i];
        cout << "\nP[" << i + 1 << "]"
             << "\t\t" << b[i] << "\t\t\t" << wt[i] << "\t\t\t\t" << tat[i];
    }
    cout << "\nWaiting Time is: " << awt << endl;
    cout << "Turn Around Time is: " << atat << endl;

    awt /= n;
    atat /= n;
    cout << "Average Wating Time is: " << awt << endl;
    cout << "Average Turn Around Time is: " << atat << endl;
    return 0;
}