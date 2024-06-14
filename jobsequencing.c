#include<stdio.h>
int main()
{int n;
printf("Enter the no. of process you want to store:"); 
scanf("%d",&n);
int process [n];
int deadline[n];
int profit[n];
int j,i, MAX_DED;
int profit_t;
for(i=0;i<n;i++)
{
printf("\nEnter the Process No:");
scanf("%d",&process[i]);
printf("\nEnter the Process Deadline:");
scanf("%d",&deadline[i]);
printf("\nEnter the Process profit:");
scanf("%d",&profit[i]);
}
printf("\nEnter the maximum deadline for schedulling:"); 
scanf("%d", &MAX_DED);
 int temp;
for ( i = 0; i < n - 1 ;i++){
    for(j=0;j<n-i-1;j++)  {
			if(profit[j]<=profit[j+1])	{
    	temp=profit[j]; 
		profit[j]=profit [j + 1] ;
		profit[j+1]=temp;

		temp=process[j];
		 process[j]=process [j + 1] ;
		process [j + 1] =temp;

		temp=deadline[j];
 		deadline[j]=deadline [j + 1];
  		deadline [j + 1] = temp;
		}  } }
printf("\n Process\tDeadline\tProfit ");
for(i=0;i<n;i++) {
printf("\n%d\t\t%d\t\t%d",process[i], deadline[i], profit[i]); }
i=0;
printf("\nScheduled process:");
while (MAX_DED!=0)
{ if(deadline[i]<=MAX_DED)
	{	profit_t+=profit[i];
		MAX_DED-=deadline[i];
		printf("\nProcess %d", process[i]);
     	i++; 	}
	else
        break; }

printf("\nTotal Profit:%d", profit_t);

}
