#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &mm, int memsize, int total)
{
    cout << "\n\tMAIN MEMEORY\n";
    cout << "\t-----------------\n";
    for (int i = 0; i < (int)mm.size(); i++)
    {
        if (mm[i][1] == -1)
            cout << "Block" << i << "\t|\t\t|   " << mm[i][0] << " MB\n";
        else
            cout << "Block" << i << "\t|\t"
                 << "P" << mm[i][1] << "\t|   " << mm[i][0] << " MB\n";
        cout << "\t-----------------\n";
    }
    cout << "Block n"
         << "\t|\t\t|   " << memsize - total << " MB\n";
    cout << "\t-----------------\n";
}

void MVT(int memsize)
{
    int t,extr_frag = 0,total = 0,p,id;
    vector<vector<int>> mm;
    cout<<"Enter number of process: ";
    cin>>t;
    while(t--){
        cout<<"Enter process id and size: ";
        cin>>id>>p;
        total+=p;
        if(total>memsize){
            cout<<"Memory is full";
            break;
        }
        else{
            mm.push_back({p,id});
            print(mm,memsize,total);
        }
    }
    cout<<"\nEnter number or process to remove: ";
    cin>>t;
    while(t--){
        cout<<"Enter process id: ";
        cin>>id;
        int i;
        for(i=0;i< (int)mm.size();i++){
            if(id == mm[i][1]){
                mm[i][1] = -1;
                extr_frag+=mm[i][0];
                print(mm,memsize,total);
                break;
            }
        }
        if(i==(int)mm.size())
            cout<<"Process not found";
    }
    cout<<"\nExternal fragmentation: "<<extr_frag;
}

int main()
{
    int memsize;
    cout << "Enter the total size of main memory(MB):";
    cin >> memsize;
    MVT(memsize);
}