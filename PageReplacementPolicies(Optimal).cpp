#include <iostream>
// optimal
using namespace std;

int main()
{
    int num_blocks, num_requests;
    cout << "Enter the number of blocks: ";
    cin >> num_blocks;

    int blocks[num_blocks];
    for (int i = 0; i < num_blocks; i++)
        blocks[i] = -1;

    int num_hits = 0;
    int num_misses = 0;

    cout << "Enter the number of requests: ";
    cin >> num_requests;

    int requests[num_requests];
    cout << "Enter the reference string: ";
    for (int i = 0; i < num_requests; i++)
        cin >> requests[i];

    for (int i = 0; i < num_requests; i++)
    {
        int page = requests[i];

        // Check if page is already in memory
        bool hit = false;
        for (int j = 0; j < num_blocks; j++)
            if (blocks[j] == page)
            {
                hit = true;
                num_hits++;
                break;
            }

        // If page is not in memory, find the page that will be used furthest in the future
        if (!hit)
        {
            num_misses++;
            int future_index[num_blocks];
            for (int j = 0; j < num_blocks; j++)
                future_index[j] = INT_MAX; // 4 3 2 1 4 3 5 4 3 2 1 5

            for (int j = i + 1; j < num_requests; j++)
                for (int k = 0; k < num_blocks; k++)
                    if (blocks[k] == requests[j])
                    {
                        future_index[k] = j;
                        break;
                    }

            int victim_index = 0;
            int max_future_index = future_index[0];
            for (int j = 1; j < num_blocks; j++)
                if (future_index[j] > max_future_index)
                {
                    victim_index = j;
                    max_future_index = future_index[j];
                }

            // Replace victim page with current page
            blocks[victim_index] = page;
        }

        // Print current state of memory
        cout << "Blocks: ";
        for (int j = 0; j < num_blocks; j++)
            if (blocks[j] == -1)
                cout << "- ";
            else
                cout << blocks[j] << " ";
        cout << endl;
    }

    double hit_ratio = (double)num_hits / num_requests;
    double miss_ratio = (double)num_misses / num_requests;
    // 4 3 2 1 4 3 5 4 3 2 1 5

    cout << "Hit ratio: " << hit_ratio << endl;
    cout << "Miss ratio: " << miss_ratio << endl;

    return 0;
}