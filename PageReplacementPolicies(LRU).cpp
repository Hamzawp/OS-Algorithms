// Write a program to implement LRU policy and calculate Hit ratio and Miss ratio
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num_pages, num_frames, page_faults = 0, hit_count = 0;
    cout << "Enter the number of frames: ";
    cin >> num_frames;
    cout << "Enter the number of pages: ";
    cin >> num_pages;

    int reference_string[num_pages];
    cout << "Enter the reference string: ";
    for (int i = 0; i < num_pages; i++)
        cin >> reference_string[i];

    int frame_buffer[num_frames];
    memset(frame_buffer, -1, sizeof(frame_buffer));
    int frame_usage[num_frames];
    memset(frame_usage, 0, sizeof(frame_usage));

    for (int i = 0; i < num_pages; i++){
        bool page_fault = true;
        int page = reference_string[i];
        for(int j=0;j<num_frames;j++){
            if(page == frame_buffer[j]){
                hit_count++;
                frame_usage[j] = i+1;
                page_fault = false;
                break;
            }
        }
        if(page_fault){
            page_faults++;
            int oldest_frame = 0;
            for(int j=0;j<num_frames;j++){
                if(frame_usage[j]<frame_usage[oldest_frame]){
                    oldest_frame = j;
                }
            }
            frame_buffer[oldest_frame] = page;
            frame_usage[oldest_frame] = i+1;
        }
        for(int j=0;j<num_frames;j++){
            if(frame_buffer[j] == -1)
                cout<<"- ";
            else
                cout<<frame_buffer[j]<<" ";
        }
        cout<<endl;
    }

    float hit_ratio = (float)hit_count / num_pages;
    float miss_ratio = (float)page_faults / num_pages;
    cout << "Hit ratio: " << hit_ratio << endl;
    cout << "Miss ratio: " << miss_ratio << endl;
    return 0;
}