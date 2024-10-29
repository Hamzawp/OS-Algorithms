#include<iostream>

using namespace std;
int main (){
    int num_blocks,num_processes;
    cout<<"Enter number of blocks: ";
    cin>>num_blocks;
    cout<<"Enter number of processes: ";
    cin>>num_processes;
    int block[num_blocks],page[num_processes];
    cout<<"Enter ref. string: ";
    for(int i=0;i<num_processes;i++)
        cin>>page[i];
    for(int i=0;i<num_blocks;i++)
        block[i]=-1;
    int nextIndex=0,hits=0,miss=0;
    for(int i=0;i<num_processes;i++){
        bool hit = false;
        for(int j=0;j<num_blocks;j++)
            if(page[i] == block[j]){
                hit = true;
                hits++;
                break;
            }
        if(!hit){ 
            miss++;
            block[nextIndex] = page[i]; 
            nextIndex = (nextIndex+1)%num_blocks;
        }
    }
    cout<<"Number of hits: "<<hits<<endl;
    cout<<"Number of misses: "<<miss;
    return 0;
}