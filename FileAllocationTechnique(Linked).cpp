#include <bits/stdc++.h>
using namespace std;

struct filetable
{
    char name[20];
    int nb;
    struct newblock *sb;
} ft[30];

struct newblock
{
    int bno;
    struct newblock *next;
};

int main()
{
    int n;
    cout << "Enter the no of files" << endl;
    cin >> n;

    struct newblock *temp;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the file name" << endl;
        cin >> ft[i].name;
        cout << "Enter the no of blocks" << endl;
        cin >> ft[i].nb;
        ft[i].sb = (struct newblock *)malloc(sizeof(struct newblock));
        temp = ft[i].sb;

        cout << "Enter the blocks of the file" << endl;
        cin >> temp->bno;
        temp->next = NULL;
        for (int j = 1; j < ft[i].nb; j++)
        {
            temp->next = (struct newblock *)malloc(sizeof(struct newblock));
            temp = temp->next;
            cin >> temp->bno;
        }
        temp->next = NULL;
    }

    char target[20];
    cout << "Enter the file name to be searched" << endl;
    cin >> target;

    int i;
    for (i = 0; i < n; i++)
        if (strcmp(target, ft[i].name) == 0)
            break;
    if (i == n)
        cout << "Page not found" << endl;
    else
    {
        temp = ft[i].sb;
        cout << "File name\tNo of Blocks\tBlock nos" << endl;
        cout << ft[i].name << "\t\t" << ft[i].nb << "\t\t";
        for (int j = 0; j < ft[i].nb; j++)
        {
            cout << temp->bno << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}