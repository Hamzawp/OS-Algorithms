#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num_processes, num_blocks;
    cout << "Number of blocks: ";
    cin >> num_blocks;
    cout << "Number of process: ";
    cin >> num_processes;

    int mem_blocks[num_blocks];
    cout << "Enter sizes of memory blocks: ";
    for (int i = 0; i < num_blocks; i++)
        cin >> mem_blocks[i];

    string process_names[num_processes];
    int size_process[num_processes];
    bool alloc_stat[num_processes];
    for (int i = 0; i < num_processes; i++)
    {
        cout << "Enter the name and size of process " << i << ": ";
        cin >> process_names[i] >> size_process[i];
        alloc_stat[i] = false;
        cout << endl;
    }
    for (int i = 0; i < num_processes; i++)
    {
        int max = INT_MIN;
        int best_fit_index = -1;
        for (int j = 0; j < num_blocks; j++)
            if (mem_blocks[j] >= size_process[i])
                if (max < (mem_blocks[j] - size_process[i]))
                {
                    max = mem_blocks[j] - size_process[i];
                    best_fit_index = j;
                }
        if (best_fit_index != -1)
        {
            mem_blocks[best_fit_index] -= size_process[i];
            alloc_stat[i] = true;
            cout << "Memory allocated for " << process_names[i] << " at index: " << best_fit_index << endl;
        }
        else
            cout << "Could not allocate memory for " << process_names[i] << endl;
    }
    return 0;
}