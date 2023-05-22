//SJF Scheduling

 #include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], i, j, awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
        wt[i] = (i == 0) ? 0 : wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess    Burst Time    Waiting Time    Turnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d         %d              %d               %d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    awt /= n;
    atat /= n;
    printf("\nAverage Waiting Time = %d", awt);
    printf("\nAverage Turnaround Time = %d\n", atat);

    return 0;
}
