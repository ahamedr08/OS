//Round Robin Scheduling
#include<stdio.h> int main()
{
int i, processes, sum=0,cnt=0, y, q, wt=0, tat=0, at[10]={0,0,0,0,0}, bt[10], temp[10]; float avg_waitt, avg_turnat;
printf("Enter the number of process :"); scanf("%d", &processes);
y = processes;
for(i=0; i<processes; i++)
{
printf("Burst time for process P[%d] :", i+1); scanf("%d", &bt[i]);
temp[i] = bt[i];
}
printf("Enter the time slice (in ms) : "); scanf("%d", &q);
printf("\nProcess\t\tBurst Time\tWaiting Time\tTurn Around Time"); for(sum=0, i = 0; y!=0; )
{
if(temp[i] <= q && temp[i] > 0)
{
sum = sum + temp[i]; temp[i] = 0;
cnt=1;
}
else if(temp[i] > 0)
{
temp[i] = temp[i] - q; sum = sum + q;
}
if(temp[i]==0 &&cnt==1)
{
y--;
printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]); wt = wt+sum-at[i]-bt[i];
tat = tat+sum-at[i]; cnt =0;
}
if(i==processes-1) i=0;
else if(at[i+1]<=sum) i++;
else
i=0;
}
avg_waitt = wt * 1.0/processes; avg_turnat = tat * 1.0/processes;
printf("\n\nAverage Turn Around Time : %f ms", avg_waitt); printf("\nAverage Waiting Time : %f ms", avg_turnat);
 
return 0;
}
