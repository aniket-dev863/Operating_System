#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of processes :\n");
    scanf("%d", &n);
    int at[n], rm[n], bt[n], wt[n], tat[n], ct[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time of %d th process:\n", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rm[i] = bt[i];
    }
    int t = 0, comp = 0;
    while (comp != n)
    {
        int minm = 1e9;
        int minInd = -1;
        int found = 0;
        for (int j = 0; j < n; j++)
        {
            if ((at[j] <= t) && (rm[j] < minm) && (rm[j] > 0))
            {
                minm = rm[j];
                minInd = j;
                found = 1;
            }
        }
        if (found == 0)
        {
            t++;
            continue;
        }
        rm[minInd]--;
        minm = rm[minInd];
        if (minm == 0)
            minm = 100000000;
        if (rm[minInd] == 0)
        {
            comp++;
            found = 0;
            int finish_time = t + 1;
            wt[minInd] = finish_time - at[minInd] - bt[minInd];
            if (wt[minInd] < 0)
                wt[minInd] = 0;
        }
        t++;
    }
    int total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("\nP \t AT \t BT \t WT \t TAT\n");
    printf("-----------------------------------------------------------");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    printf("Average TAT %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time %.2f\n", (float)total_wt / n);
    return 0;
}
