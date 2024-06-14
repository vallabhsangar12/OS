#include<stdio.h>

int main(){
	int mSize,os_Size,user_mem;
	int n,i,j;
	
	printf("Enter size of main memory: ");
	scanf("%d",&mSize);
	os_Size=(mSize*2)/5;
	user_mem=(mSize*3)/5;
	
	printf("Enter no. of Processes: ");
	scanf("%d",&n);
	
	int req_frame[n];
	int pid[n],req_mem[n];
	
	for(i=0;i<n;i++){
		printf("Enter process ID and required memory space: ");
		scanf("%d%d",&pid[i],&req_mem[i]);
	}
		
	printf("process ID \t\t Req_Memory \n");
	for(i=0;i<n;i++){
		printf("%d \t\t\t %d \n",pid[i],req_mem[i]);
	}
	
	i=0;
	while(user_mem!=0){
		if(req_mem[i]<=user_mem){
			user_mem-=req_mem[i];
			i++;
		}
		else{
			
			break; 		}	}
		printf("\nExecuted Process \n");
	for(j=0;j<i;j++){
		printf("Process %d\n",pid[j]);
	}
	printf("Waiting Process \n");
	for(j=i;j<n;j++){
		printf("Process %d\n",pid[j]);	
	}
}

