#include <cstring>
#include <iostream>

using namespace std;

bool findSafeSequence(int max[][10], int allocated[][10], int available[], int m, int n, int safeSeq[])
{
    bool finish[n];
    for (int i = 0; i < n; i++)
        finish[i] = false;

    int count = 0;
    while (count < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
            if (!finish[i])
            {
                int j;
                for (j = 0; j < m; j++)
                    if (max[i][j] - allocated[i][j] > available[j])
                        break;
                if (j == m)
                {
                    for (j = 0; j < m; j++)
                        available[j] += allocated[i][j];
                    finish[i] = true;
                    safeSeq[count++] = i;
                    found = true;
                }
            }
        if (!found)
            return false;
    }
    return true;
}

int main()
{
    int n, m;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    int max[10][10];
    int allocated[10][10];
    int available[10];
    int safeSeq[10];

    cout << "Enter the maximum resource requirements for each process: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "Enter the allocated resource for each process: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> allocated[i][j];

    cout << "Enter the available resources: ";
    for (int i = 0; i < m; i++)
        cin >> available[i];

    if (findSafeSequence(max, allocated, available, m, n, safeSeq))
    {
        cout << "Safe sequence: ";
        for (int i = 0; i < n; i++)
            cout << "P" << safeSeq[i] << " ";
        cout << endl;
    }
    else
        cout << "No safe sequence exists." << endl;

    return 0;
}