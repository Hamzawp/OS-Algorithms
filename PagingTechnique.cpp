#include <bits/stdc++.h>

using namespace std;
int main()
{
    int pro_size, pg_size, phy_mem;
    int num_pages, logicbits, physicalbits, num_frames, num_entries;

    cout << "Enter process size(Kb): ";
    cin >> pro_size;
    cout << "Enter page size(bytes): ";
    cin >> pg_size;
    cout << "Enter physical memory(mb): ";
    cin >> phy_mem;

    logicbits = log2(pro_size) + 10;
    pg_size = log2(pg_size);
    num_pages = logicbits - pg_size;

    cout << "\nNumber of bits in Logical Address:2^(" << logicbits
         << ") = " << logicbits << " bits";
    cout << "\nNumber of pages in Logical Address:2^(" << num_pages << ") and ";
    cout << "\nOffset bits in Logical adress is: " << pg_size << " bits";

    physicalbits = log2(phy_mem) + 20;
    num_frames = physicalbits - pg_size;

    cout << "\nNumber of bits in Physical Address:2^(" << physicalbits
         << ") = " << physicalbits << " bits";
    cout << "\nNumber of frames in Physical Address:2^(" << num_frames << ")\n";

    num_entries = pow(2, num_pages);

    int pageNum[10], frameNum[10], validBit[10];
    cout << "\nEnter page number, frame number, and valid bit for up to 5 "
            "pages:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "Page " << i + 1 << ": ";
        cin >> pageNum[i] >> frameNum[i] >> validBit[i];
        if (pageNum[i] == -1)
            break;
    }
    cout << "\nPage Table\n";
    cout << "----------\n";
    cout << "Page no.\tFrame no.\tValid bit\n";
    for (int i = 0; i < 5; i++)
        if (frameNum[i] == -1)
            cout << pageNum[i] << "\t\t--\t\t" << validBit[i] << "\n";
        else
            cout << pageNum[i] << "\t\t" << frameNum[i] << "\t\t" << validBit[i]
                 << "\n";
    cout << "...\t\t...\t\t...\n"
         << num_entries << "\t\t...\t\t...\n";

    string pageuserinput, offsetuserinput;
    cout << "\nEnter the logical address: ";
    cin >> pageuserinput >> offsetuserinput;
    int userpageno = stoi(pageuserinput, nullptr, 2);
    if (validBit[userpageno] == 0)
        cout << "\nPage Fault";
    else
        cout << "Page Hit";

    return 0;
}