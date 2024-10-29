#include <bits/stdc++.h>
using namespace std;

int findShortest(int head, int *queue, int n)
{
    int mini = INT_MAX, index;
    for (int i = 0; i < n; i++)
        if (mini > abs(head - queue[i]))
        {
            mini = abs(head - queue[i]);
            index = i;
        }
    return index;
}

int main()
{
    int head, n, range, total = 0;

    cout << "Enter the head position: ";
    cin >> head;

    cout << "\nEnter the number of requests: ";
    cin >> n;

    cout << "\nEnter the range of cylinder: ";
    cin >> range;

    int queue[n];
    cout << "\nEnter the cylinder numbers for the requests: ";
    for (int i = 0; i < n; i++)
        cin >> queue[i];

    cout << "\nThe order of execution: " << endl;
    for (int i = 0; i < n; i++)
    {
        int index = findShortest(head, queue, n);
        total += abs(head - queue[index]);
        cout << head << "->" << queue[index] << endl;
        head = queue[index];
        queue[index] = INT_MAX;
    }

    cout << "\nTotal Headmovements: " << total;

    return 0;
}