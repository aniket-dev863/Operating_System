#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of processes :\n");
    scanf("%d", &n);
    int at[n], bt[n], origBT[n], wt[n], tat[n], ct[n], pr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the AT , BT and priority of process %d", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
    }
    int rem[n];
    for (int i = 0; i < n; i++)
    {
        rem[i] = bt[i];
    }
    int comp = 0;
    int time = 0;
    while (comp != n)
    {
        int minpr = -1;
        int minInd = -1;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && (pr[i] > minpr) && (rem[i] > 0))
            {
                minpr = pr[i];
                minInd = i;
            }
        }
        if (minpr == -1)
        {
            time++;
            continue;
        }
        rem[minInd]--;
        time++;
        if (rem[minInd] == 0)
        {
            comp++;
            int finishtime = time;
            tat[minInd] = finishtime - at[minInd];
            wt[minInd] = tat[minInd] - bt[minInd];
            if (wt[minInd] < 0)
                wt[minInd] = 0;
        }
    }
    return 0;
}