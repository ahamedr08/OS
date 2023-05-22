//FCFS Scheduling
#include <stdio.h>

int main() {
    int n, bt[30], wt[30], tat[30], awt = 0, atat = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);

        if (i == 0) {
            wt[i] = 0;
        } else {
            wt[i] = wt[i - 1] + bt[i - 1];
        }

        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    awt /= n;
    atat /= n;
    printf("Average waiting time: %d\n", awt);
    printf("Average turnaround time: %d\n", atat);

    return 0;
}
