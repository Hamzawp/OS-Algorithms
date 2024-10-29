#include <iostream>
#include <string.h>
using namespace std;

struct table
{
    char name[20];
    int sb, nob;
} ft[30];

int main()
{
    int n, count = 0;
    char filename[20];
    cout << "Enter number of files: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "File " << i + 1 << " name: ";
        cin >> ft[i].name;
        cout << "Starting block: ";
        cin >> ft[i].sb;
        cout << "Number of blocks: ";
        cin >> ft[i].nob;
    }
    cout << "Enter file name to be searched: ";
    cin >> filename;
    for (int i = 0; i < n; i++)
        if (strcmp(filename, ft[i].name) == 0)
        {
            count++;
            break;
        }
    if (count == 0)
        cout << "File not found" << endl;
    else
    {
        cout << "\nFile Name\tStarting Block\tNo. of Blocks\tBlocks Occupied" << endl;
        cout << ft[count - 1].name << "\t\t" << ft[count - 1].sb << "\t\t" << ft[count - 1].nob << "\t\t";
        for (int j = 0; j < ft[count - 1].nob; j++)
            cout << ft[count - 1].sb + j << ",";
    }
    return 0;
}