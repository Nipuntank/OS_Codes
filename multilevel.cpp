#include <iostream>
#include <queue>
using namespace std;
class process
{
public:
    char name;
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
    int rem_bt;
    int index;
};
queue<process> q1;
queue<process> q2;
queue<process> q3;
void FCFS(process p[], int n, int &time)
{
    process front = q3.front();
    int i = front.index;
    q3.pop();
    time += front.rem_bt;
    p[i].ct = time;
}

void RR1(process p[], int n, int t, int &time)
{
    process front = q1.front();
    int i = front.index;
    q1.pop();
    if (front.rem_bt > t)
    {
        time += t;
        front.rem_bt -= t;
        q2.push(front);
    }
    else
    {
        time += front.rem_bt;
        front.rem_bt = 0;
        p[i].ct = time;
    }
}
void RR2(process p[], int n, int t, int &time)
{
    process front = q2.front();
    int i = front.index;
    q2.pop();
    if (front.rem_bt > t)
    {
        time += t;
        front.rem_bt -= t;
        q3.push(front);
    }
    else
    {
        time += front.rem_bt;
        front.rem_bt = 0;
        p[i].ct = time;
    }
}
void CT(process p[], int n, int t1, int t2)
{
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        q1.push(p[i]);
    }
    while (!q1.empty())
    {
        RR1(p, n, t1, time);
    }
    while (!q2.empty())
    {
        RR2(p, n, t2, time);
    }
    while (!q3.empty())
    {
        FCFS(p, n, time);
    }
}
void TAT(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
    }
}
void WT(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].wt = p[i].tat - p[i].bt;
    }
}
void MaxTAT(process p[], int n)
{
    int maxi = 0, index = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxi < p[i].tat)
        {
            maxi = p[i].tat;
            index = i;
        }
    }
    cout << endl
         << "Maximum TAT is of process " << p[index].name << " with TAT = " << p[index].tat << endl;
}
int main()
{
    int n;
    cout << "Enter the number of process:";
    cin >> n;
    class process p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name;
        cin >> p[i].bt;
        p[i].rem_bt = p[i].bt;
        p[i].tat = 0;
        p[i].ct = 0;
        p[i].wt = 0;
        p[i].at = 0;
        p[i].index = i;
    };
    cout << "Enter the time quantum of two queues:";
    int t1, t2;
    cin >> t1 >> t2;
    if (t2 > t1)
    {
        cout << "Time Quantum of queue 1 should be greater" << endl;
    }
    else
    {
        CT(p, n, t1, t2);
        TAT(p, n);
        WT(p, n);
        cout << "Name"
             << "\t"
             << "AT"
             << "\t"
             << "BT"
             << "\t"
             << "CT"
             << "\t"
             << "TAT"
             << "\t"
             << "WT"
             << "\t" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << p[i].name << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
        }
        MaxTAT(p, n);
    }

    return 0;
}
