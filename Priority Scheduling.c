//Priority Scheduling
#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], p[20], pr[20], i, j, awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time and Priority:\n");
    for (i = 0; i < n; i++) {
        printf("P%d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }

    // Sorting based on priority using selection sort
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        wt[i] = (i == 0) ? 0 : wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess    Burst Time    Priority    Waiting Time    Turnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d         %d            %d             %d               %d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }
    awt /= n;
    atat /= n;
    printf("\nAverage Waiting Time = %d", awt);
    printf("\nAverage Turnaround Time = %d\n", atat);

    return 0;
}