#include <stdio.h>

int main() {
     int i;
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {10, 5, 8};

    
    int wt[n], tat[n];

    wt[0] = 0;

    for ( i = 1; i < n; i++) {
        wt[i] = burst_time[i - 1] + wt[i - 1];
    }

    for ( i = 0; i < n; i++) {
        tat[i] = burst_time[i] + wt[i];
    }

    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");

    int total_wt = 0, total_tat = 0;
    for ( i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], wt[i], tat[i]);
    }

    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;

    printf("Average waiting time = %.2f\n", avg_wt);
    printf("Average turnaround time = %.2f\n", avg_tat);

    return 0;
}
