/*
 * C Program to implement the Banker's Algorithm
 * for Deadlock Avoidance.
 *
 * This program determines if the current system state
 * is SAFE or UNSAFE. If safe, it prints a safe sequence.
 */

#include <stdio.h>

int main()
{
    int n, m; // n = processes, m = resource types

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    // --- Input Data ---

    int available[m];
    int max[n][m];
    int allocation[n][m];
    int need[n][m];

    printf("\nEnter the AVAILABLE instances for each resource type:\n");
    for (int j = 0; j < m; j++)
    {
        printf("  Resource %d: ", j);
        scanf("%d", &available[j]);
    }

    printf("\nEnter the MAX matrix (max need for each process):\n");
    for (int i = 0; i < n; i++)
    {
        printf("  For Process %d: ", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter the ALLOCATION matrix (currently allocated):\n");
    for (int i = 0; i < n; i++)
    {
        printf("  For Process %d: ", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // --- 1. Calculate the NEED matrix ---
    // Need[i][j] = Max[i][j] - Allocation[i][j]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // --- 2. Initialize Safety Algorithm data ---

    // 'work' vector, initialized to available
    int work[m];
    for (int j = 0; j < m; j++)
    {
        work[j] = available[j];
    }

    // 'finish' vector, all initialized to 0 (false)
    int finish[n];
    for (int i = 0; i < n; i++)
    {
        finish[i] = 0; // 0 = false
    }

    int safe_sequence[n];
    int count = 0; // Counts completed processes

    // --- 3. Run the Safety Algorithm ---

    // Loop until all processes are finished or we get stuck
    while (count < n)
    {
        int found_process = 0; // Flag to check if we found a process to run

        // Iterate through all processes
        for (int i = 0; i < n; i++)
        {

            // Check 1: Is process 'i' already finished?
            if (finish[i] == 0)
            {

                // Check 2: Can process 'i's NEED be met by 'work'?
                int can_allocate = 1; // Assume true
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        can_allocate = 0; // False, need is too high
                        break;            // Stop checking resources for this process
                    }
                }

                // If both checks pass (not finished AND needs <= work)
                if (can_allocate == 1)
                {

                    // "Run" the process:
                    // 1. "Release" its resources and add to work
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }

                    // 2. Mark process as finished
                    finish[i] = 1; // true

                    // 3. Add to safe sequence
                    safe_sequence[count] = i;

                    // 4. Increment completed count
                    count++;

                    // 5. Set flag
                    found_process = 1;
                }
            }
        } // end of for loop (checking all processes)

        // If we went through all processes and found NO process
        // that could run, the system is in an unsafe state.
        if (found_process == 0)
        {
            break; // Exit the while loop
        }
    } // end of while loop

    // --- 4. Check the result ---
    printf("\n--- Results ---\n");

    // Print the calculated Need Matrix
    printf("Need Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("  P%d: ", i);
        for (int j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    if (count == n)
    {
        // All processes finished
        printf("\nSystem is in a SAFE STATE.\n");
        printf("Safe Sequence: < ");
        for (int i = 0; i < n; i++)
        {
            printf("P%d ", safe_sequence[i]);
        }
        printf(">\n");
    }
    else
    {
        // The while loop broke early (count < n)
        printf("\nSystem is in an UNSAFE STATE.\n");
        printf("Deadlock is possible. %d process(es) could not finish.\n", n - count);
    }

    return 0;
}