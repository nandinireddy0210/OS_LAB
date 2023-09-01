#include<stdio.h>
int main()
{
int wt[10],bt[10],tat[10],i,n;
float wtavg,tatavg;
printf("Enter no of Processes --");
scanf("%d\n",&n);
for(i=0;i<n;i++)
{
printf("Enter burst time for process %d--",i);
scanf("%d\n",&bt[i]);
}
wt[0]=wtavg=0;
tat[0]=tatavg=bt[0];
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
wtavg=wtavg+wt[i];
tatavg=tatavg+tat[i];
}
printf("\tProcess\tBurst Time\tWaiting Time\tTurn Around Time");
for(i=0;i<n;i++)
  printf("\n\tP%d\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tat[i]);
  printf("Average Waiting time :%f",wtavg/n);
printf("Average Turn around time :%f",tatavg/n);
return 0;
}
