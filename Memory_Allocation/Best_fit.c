#include <stdio.h>
#include <stdlib.h>
int n;
int npr;
int *mem;
int *pr;
int *alloc;
int main()
{
    printf("Enter the number of memory blocks: \n ");
    scanf("%d", &n);
    mem = (int *)malloc(n * sizeof(int));
    alloc = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the size of %d memory Block \n", i + 1);
        scanf("%d", &mem[i]);
        alloc[i] = 0;
    }
    printf("Enter the number of Processes :\n");
    scanf("%d", &npr);
    pr = (int *)malloc(npr * sizeof(int));
    for (int i = 0; i < npr; i++)
    {
        printf("Enter the memory required for %d th process:\n ", i + 1);
        scanf("%d", &pr[i]);
    }
    for (int i = 0; i < npr; i++)
    {
        int min_diff = 1e9;
        int min_id = -1;
        for (int ij = 0; ij < n; ij++)
        {
            if (alloc[ij] == 0 && mem[ij] >= pr[i])
            {
                int diff = mem[ij] - pr[i];
                if (diff < min_diff)
                {
                    min_diff = diff;
                    min_id = ij;
                }
            }
        }
        if (min_id != -1)
        {
            alloc[min_id] = pr[i];
            printf("Process %d which needed %d allocated %d kb  memory \n", i, pr[i], mem[min_id]);
        }
        else
        {
            printf("Process %d which needed %d allocated  0 kb  memory \n", i, pr[i]);
        }
    }
    return 0;
}