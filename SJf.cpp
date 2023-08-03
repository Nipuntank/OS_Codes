#include<iostream>
using namespace std;
class process
{
    public:
    char name;
    int bt;
    int wt;
    int tat;
    int at;
};
void TAT(process p[],int n)
{
    for(int i=0;i<n;i++)
    {
        p[i].tat=p[i].bt+p[i].wt;
    }
}
void waitingTime(process p[],int n)
{
    for(int i=1;i<n;i++)
    {
        p[i].wt=p[i-1].wt+p[i-1].bt;
    }
}
bool st(process p1,process p2)
{
    return p1.bt<p2.bt;
}
void avgTime(process p[],int n)
{
    sort(p,p+n,st);
    waitingTime(p,n);
    TAT(p,n);
    int total_wt=0;
    int total_tat=0;
    for(int i=0;i<n;i++)
    {
        total_wt +=p[i].wt;
        total_tat+=p[i].tat;
    }
    float avgWt = total_wt/(float)n;
    float avgTat = total_tat/(float)n;
    cout<<"avg wt:"<<avgWt<<endl;
    cout<<"avg Tat:"<<avgTat<<endl;

}
void printEle(process p[],int n)
{
    cout<<"Name "<<"AT"<<" BT"<<" WT"<<" Tat"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].name<<"    "<<p[i].at<<"  "<<p[i].bt<<"  "<<p[i].wt<<"   "<<p[i].tat<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of process:";
    cin>>n;
    process p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].name;
        cin>>p[i].at;
        cin>>p[i].bt;
        p[i].wt=0;
        p[i].tat=0;
    }
    avgTime(p,n);
    printEle(p,n);
    
    return 0;
}