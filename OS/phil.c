#include <stdio.h>
#include <stdlib.h>
void one();
void two();
int phil[10],philnum,hung[10],hungnum,status[10];
void main()
{
	int ch,i,j; 
	printf("Enter the total no of philosophers:");
	scanf("%d",&philnum);
	for(i=0;i<philnum;i++)
	{
		phil[i]=i+1;
		status[i]=1;
	}
	printf("how many philosophers are hungry:");
	scanf("%d",&hungnum);
	if(philnum==hungnum)
	{
		printf("total philosophers are hungry\nDead lock will be occur\nExiting");
		return;
	}
	else
	{
		for(j=0;j<hungnum;j++)
		{
			printf("Enter the philosopher and its postion:");
			scanf("%d",&hung[j]);
		}
		do{
			printf("1.One can eat at a time 2.Two can eat at a time 3.Exit\nEnter your choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: one();
					break;
				case 2: two();
					break;
				case 3: return;
				default:printf("Invalid choice\n");
			}
		}while(1);
	}
}
void one()
{
	int pos=0,i,j;
	printf("one philosophen is allow to eat at a time\n");
	for(i=0;i<hungnum;i++,pos++)
	{
		printf("p%d is granted\n",phil[hung[pos]-1]);
		for(j=pos;j<hungnum;j++)
		{
			printf("p%d is waiting\n",phil[hung[j]-1]);
		}
	}
	return;
}
void two()
{
	int i, j, s=0, t, r, x;
	printf("two philosophen is allow  to eat at a time\n");
	for(i=0;i<hungnum;i++)
	{
		for(j=i+1;j<hungnum;j++)
		{
			if(abs(hung[i]-hung[j])>=1&& abs(hung[i]-hung[j])!=4)
			{
				printf("combination %d \n", (s+1));
				t=hung[i];
				r=hung[j]; 
				s++;
				printf("P %d and P %d are granted to eat\n", phil[hung[i]-1],phil[hung[j]-1]);
				for(x=0;x<hungnum;x++)
				{
					if((hung[x]!=t)&&(hung[x]!=r))
					{
						printf("P %d is waiting\n", phil[hung[x]-1]);
					}
				}
			}
		}
	}
	return;
}
				
