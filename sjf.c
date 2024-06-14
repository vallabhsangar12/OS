#include <stdio.h>

int main() {
    int n, i, j, temp;
    int bt[20], at[10], st[10], ft[10], wt[10], ta[10];
    int totwt = 0, totta = 0;
    double awt, ata;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process name, arrival time, and burst time:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &at[i], &bt[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            st[i] = at[i];
        } else {
            st[i] = ft[i - 1];
        }
        wt[i] = st[i] - at[i];
        ft[i] = st[i] + bt[i];
        ta[i] = ft[i] - at[i];
        totwt += wt[i];
        totta += ta[i];
    } awt = (double)totwt / n;
    ata = (double)totta / n;
   printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], ta[i]);   }
    printf("\nAverage waiting time: %.2f", awt);
    printf("\nAverage turnaround time: %.2f", ata);
   return 0; }
