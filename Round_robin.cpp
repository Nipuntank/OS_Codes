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
void waitingTime(process p[],int n,int q)
{
    int rem_bt[n];
	for (int i = 0 ; i < n ; i++)
		rem_bt[i] = p[i].bt;

	int t = 0; 	
	while (1)
	{
		bool done = true;
		for (int i = 0 ; i < n; i++)
		{
			
			if (rem_bt[i] > 0)
			{
				done = false; 

				if (rem_bt[i] > q)
				{
					
					t += q;
					rem_bt[i] -= q;
				}
				else
				{
					
					t = t + rem_bt[i];
					p[i].wt = t - p[i].bt;
					rem_bt[i] = 0;
				}
			}
		}
		if (done == true)
		break;
	}
}
void avgTime(process p[],int n,int q)
{
    waitingTime(p,n,q);
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
    cout<<"Name"<<"\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"WT"<<"\t"<<"Tat"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].name<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].wt<<"\t"<<p[i].tat<<endl;
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
    int TimeQuant;
    cin>>TimeQuant;
    avgTime(p,n,TimeQuant);
    printEle(p,n);
    
    return 0;
}