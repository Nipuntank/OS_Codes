#include <iostream>
using namespace std;
void firstFit(int blockSize[], int processSize[], int m, int n)
{
    vector<int> arr(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (processSize[i] <= blockSize[j])
            {
                arr[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    cout<<"First Fit"<<endl;
    cout << "Process ID"
         << "\t"
         << "Process Size"
         << "\t"
         << "Alloted block" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t \t" << processSize[i] << "\t \t";
        if (arr[i] != -1)
        {
            cout << arr[i] + 1 << endl;
        }
        else
        {
            cout << "Not Alloted" << endl;
        }
    }
    cout<<endl;
}
void bestFit(int blockSize[], int processSize[], int m, int n)
{
    vector<int> arr(n, -1);
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;
        int index = 0;
        for (int j = 0; j < m; j++)
        {
            int left = blockSize[j] - processSize[i];
            if (processSize[i] <= blockSize[j] && left < min)
            {
                arr[i] = j;
                min = left;
            }
            if (j == n - 1)
                {
                    if(arr[i]!=-1)
                    {
                        blockSize[arr[i]] -= processSize[i];
                    }
                    
                }
        }
    }
    cout<<"Best Fit"<<endl;
    cout << "Process ID"
         << "\t"
         << "Process Size"
         << "\t"
         << "Alloted block" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t \t" << processSize[i] << "\t \t";
        if (arr[i] != -1)
        {
            cout << arr[i] + 1 << endl;
        }
        else
        {
            cout << "Not Alloted" << endl;
        }
    }
    cout<<endl;
}
void worstFit(int blockSize[], int processSize[], int m, int n)
{
    vector<int> arr(n, -1);
    for (int i = 0; i < n; i++)
    {
        int max = -1;
        for (int j = 0; j < m; j++)
        {
            int left = blockSize[j] - processSize[i];
            if (processSize[i] <= blockSize[j] && max < left)
            {
                arr[i] = j;
                max = left;
            }
            if (j == n - 1)
            {
                if(arr[i]!=-1)
                {
                    blockSize[arr[i]] -= processSize[i];
                }
                
            }
        }
    }
    cout<<"Worst Fit"<<endl;
    cout << "Process ID"
         << "\t"
         << "Process Size"
         << "\t"
         << "Alloted block" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t \t" << processSize[i] << "\t \t";
        if (arr[i] != -1)
        {
            cout << arr[i] + 1 << endl;
        }
        else
        {
            cout << "Not Alloted" << endl;
        }
    }
    cout<<endl;
}
int main()
{
    int m, n;
    cout << "Enter the number of blocks:";
    cin >> m;
    cout << "Enter the number of process:";
    cin >> n;
    int blockSize[m];
    int processSize[n];
    for (int i = 0; i < m; i++)
    {
        cin >> blockSize[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> processSize[i];
    }
    // firstFit(blockSize,processSize,m,n);
    // bestFit(blockSize,processSize,m,n);
    worstFit(blockSize, processSize, m, n);
    return 0;
}
// 100 500 200 300 600 212 417 112 426
// 200 400 600 500 200 250 357 210 468 491