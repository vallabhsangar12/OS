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
	int fix_part=5,req_frame[n];
	int pid[n],req_mem[n];
	for(i=0;i<n;i++){
		printf("Enter process ID and required memory space: ");
		scanf("%d%d",&pid[i],&req_mem[i]);
	}
	for(i=0;i<n;i++){
		req_frame[i]=req_mem[i]/fix_part;
	}	
	printf("process ID \t\t Req_Memory \t\t Req_Frame\n");
	for(i=0;i<n;i++){
		printf("%d \t\t\t %d \t\t\t %d \n",pid[i],req_mem[i],req_frame[i]);
	}	
	int total_no_frame=user_mem/fix_part;	
	printf("\nTotal no. of Frame: %d",total_no_frame);
	printf("\nFrame Size: %d",fix_part);	
	i=0;
	while(total_no_frame!=0){
		if(req_frame[i]<=total_no_frame){
			total_no_frame-=req_frame[i];
			i++;
		}
		else{
			printf("\nRemaining Frames: %d\n",total_no_frame);
			break;	}	}
		printf("\nExecuted Process \n");
	for(j=0;j<i;j++){
		printf("Process %d\n",pid[j]);
	}
	printf("Waiting Process \n");
	for(j=i;j<n;j++){
		printf("Process %d\n",pid[j]);	
	}
}

