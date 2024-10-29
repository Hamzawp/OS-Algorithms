#include <bits/stdc++.h>
using namespace std;

// direction towards large value

int findShortest(int head, int *queue, int n)
{
    int index;
    for (int i = 0; i < n; i++)
        if (queue[i] < head)
            index = i;
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
    sort(queue, queue + n);

    cout << "\nThe order of execution: " << endl;

    int index = findShortest(head, queue, n);

    total += abs(head - queue[index + 1]);
    cout << head << "-->" << queue[index + 1] << endl;

    for (int i = index + 1; i < n - 1; i++)
    {
        total += abs(queue[i + 1] - queue[i]);
        cout << queue[i] << "-->" << queue[i + 1] << endl;
    }

    total += abs(queue[n - 1] - queue[index]);
    cout << queue[n - 1] << "-->" << queue[index] << endl;

    for (int i = index; i > 0; i--)
    {
        total += abs(queue[i] - queue[i - 1]);
        cout << queue[i] << "-->" << queue[i - 1] << endl;
    }
    
    cout << "\nTotal Headmovements: " << total;

    return 0;
}