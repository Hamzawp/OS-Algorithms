#include <iostream>

using namespace std;
int main()
{
    int n, range, head, tot_mov = 0;
    cout << "Enter head position: ";
    cin >> head;
    cout << "Enter range of cylinder: ";
    cin >> range;
    cout << "Enter number of requests: ";
    cin >> n;
    int queue[n];
    cout << "Enter process requests: ";
    for (int i = 0; i < n; i++)
        cin >> queue[i];

    tot_mov += abs(head - queue[0]);
    cout << head << " -> " << queue[0] << endl;

    for (int i = 1; i < n; i++)
    {
        tot_mov += abs(queue[i] - queue[i - 1]);
        cout << queue[i - 1] << " -> " << queue[i] << endl;
    }
    cout << "Total head movement: " << tot_mov;
    return 0;
}