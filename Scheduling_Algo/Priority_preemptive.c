/*
 * C Program to implement Preemptive Priority
 * CPU Scheduling Algorithm
 *
 * This program calculates Average Waiting Time and Average Turnaround Time.
 * NOTE: Assumes a LOWER priority number means a HIGHER priority.
 */

#include <stdio.h>
#include <limits.h> // We need this for INT_MAX

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Arrays for process details
    int at[n], bt[n], rt[n], wt[n], tat[n], priority[n];

    // Store the original burst times for final TAT/WT calculation
    int original_bt[n];

    for (int i = 0; i < n; i++)
    {
        printf("--- Process %d ---\n", i);
        printf("  Enter Arrival Time: ");
        scanf("%d", &at[i]);
        printf("  Enter Burst Time: ");
        scanf("%d", &bt[i]);
        printf("  Enter Priority: ");
        scanf("%d", &priority[i]);

        rt[i] = bt[i];          // rt is remaining time
        original_bt[i] = bt[i]; // Save original burst time
    }

    int current_time = 0; // System clock
    int completed = 0;    // Counter for completed processes

    double total_wt = 0;
    double total_tat = 0;

    // Main simulation loop
    while (completed != n)
    {

        // --- Find the process with the HIGHEST priority (lowest number) ---

        // Start with the lowest possible priority
        int highest_priority = INT_MAX;
        int highest_priority_idx = -1; // Index of the process to run

        for (int j = 0; j < n; j++)
        {
            // Check if process has arrived (at[j] <= current_time)
            // AND it's not finished (rt[j] > 0)
            // AND it has a higher priority than the one we've found so far
            if ((at[j] <= current_time) && (priority[j] < highest_priority) && (rt[j] > 0))
            {
                highest_priority = priority[j];
                highest_priority_idx = j;
            }
        }

        // --- Execute the process (or idle) ---

        // Case 1: No process is ready (CPU is idle)
        if (highest_priority_idx == -1)
        {
            current_time++; // Just move the clock forward
        }
        // Case 2: A process is found
        else
        {
            // "Run" the process for one time unit
            rt[highest_priority_idx]--;

            // Increment the clock
            current_time++;

            // Check if this process just finished
            if (rt[highest_priority_idx] == 0)
            {
                completed++;

                // Calculate metrics for the completed process
                int finish_time = current_time;
                tat[highest_priority_idx] = finish_time - at[highest_priority_idx];
                wt[highest_priority_idx] = tat[highest_priority_idx] - original_bt[highest_priority_idx];

                // Ensure waiting time is not negative
                if (wt[highest_priority_idx] < 0)
                {
                    wt[highest_priority_idx] = 0;
                }

                // Add to totals
                total_tat += tat[highest_priority_idx];
                total_wt += wt[highest_priority_idx];
            }
        }
    }

    // --- All processes are complete. Print the results. ---

    printf("\nP \t AT \t BT \t Prio \t WT \t TAT\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        // Print the original burst time
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, at[i], original_bt[i], priority[i], wt[i], tat[i]);
    }

    printf("\nAverage TAT: %.2f\n", (total_tat / n));
    printf("Average Waiting Time: %.2f\n", (total_wt / n));

    return 0;
}