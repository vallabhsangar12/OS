#include <stdio.h>
#define MAX_PROCESSES 10
int j,i;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int priority[], int burst[], int n) {
	
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                swap(&priority[j], &priority[j + 1]);
                swap(&burst[j], &burst[j + 1]);
            } }}}
void findWaitingTime(int processes[], int burst[], int priority[], int waiting[], int n) {
    waiting[0] = 0; 
    for ( i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1]; } }
void findTurnaroundTime(int processes[], int burst[], int waiting[], int turnaround[], int n) {
    for ( i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];   }}
 int main() {
    int processes[MAX_PROCESSES]; int burst[MAX_PROCESSES]; int priority[MAX_PROCESSES]; int waiting[MAX_PROCESSES];
	int turnaround[MAX_PROCESSES];
    int n;
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    printf("Enter burst time and priority for each process:\n");
    for ( i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &burst[i], &priority[i]);
        processes[i] = i + 1; }
    bubbleSort(priority, burst, n);
    findWaitingTime(processes, burst, priority, waiting, n);
 
    findTurnaroundTime(processes, burst, waiting, turnaround, n);

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    for ( i = 0; i < n; i++) {
        totalWaitingTime += waiting[i];
        totalTurnaroundTime += turnaround[i];   }
    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for ( i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst[i], priority[i], waiting[i], turnaround[i]);}
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    return 0;}
