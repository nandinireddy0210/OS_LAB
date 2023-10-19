#include <stdio.h>
void main()
{
	int buffer[10],buffsize=10,in=0,out=0,ch;
	while(ch!=3)
	{
		printf("1.produce 2.consume 3.exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if((in+1)%buffsize==out)
				{
					printf("buffer is full\n");
				}
				else
				{
					printf("Enter the value:");
					scanf("%d",&buffer[in]);
					in=(in+1)%buffsize;
				}
				break;
			case 2:if(in==out)
				{
					printf("buffer is empty\n");
				}
				else{
					printf("consumed value is %d\n",buffer[out]);
					out=(out+1)%buffsize;
				}
				break;
			case 3: return;
			default:printf("invalid choice\n");
		}
	}
}
				
