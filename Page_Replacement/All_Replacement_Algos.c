#include <stdio.h>
#define FRAMES 4
#define MAX_PAGES 50
typedef struct
{
    int pageHit;
    int pageFault;
} Result;
void printResult(char *Algo, Result r, int totalpages)
{
    printf("Printing the Final Result \n");
    printf("%s Page Replacement Result \n", Algo);
    printf("=================================================\n");
    printf("Total Page Faults: %d \n", r.pageFault);
    printf("Total Page Hits : %d \n", r.pageHit);
    printf("Hit Ratio: %.2f\n", (float)r.pageHit / totalpages);
    printf("==================================================\n");
}

Result FIFO(int pages[], int n)
{
    int frame[FRAMES];
    for (int i = 0; i < FRAMES; i++)
    {
        frame[i] = -1;
    }
    Result r = {0, 0};
    int replaceIndex = 0;
    printf("\n Page \t\tFrames\t\t\t Status \n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        // Page Hit Condition .
        for (int j = 0; j < FRAMES; j++)
        {
            if (pages[i] == frame[j])
            {
                r.pageHit++;
                found = 1;
                break;
            }
        }
        // Page Fault Condition .
        if (!found)
        {
            int placed = 0;
            for (int j = 0; j < FRAMES; j++)
            {
                if (frame[j] == -1)
                {
                    placed = 1;
                    r.pageFault++;
                    frame[j] = pages[i];
                    break;
                }
            }
            if (!placed)
            {
                r.pageFault++;
                frame[replaceIndex] = pages[i];
                replaceIndex = (replaceIndex + 1) % FRAMES;
            }
        }
        printf("\n %d \t\t", pages[i]);
        for (int ij = 0; ij < FRAMES; ij++)
        {
            if (frame[ij] == -1)
                printf(" - ");
            else
            {
                printf(" %d ", frame[ij]);
            }
        }
        if (found)
        {
            printf("\t\t\tHIT\n");
        }
        else
            printf("\t\t\tFAULT\n");
    }
    return r;
}
Result LRU(int pages[], int n)
{
    int frame[FRAMES];
    for (int i = 0; i < FRAMES; i++)
    {
        frame[i] = -1;
    }
    int time = 0;
    int rec[FRAMES];
    for (int i = 0; i < FRAMES; i++)
    {
        rec[i] = 0;
    }
    Result r = {0, 0};
    printf("\n Page \t\tFrames\t\t\t Status \n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        // HIT
        int found = 0;
        for (int j = 0; j < FRAMES; j++)
        {
            if (pages[i] == frame[j])
            {
                rec[j] = ++time;
                r.pageHit++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int min_rec = 1000000;
            int replaceIndex = -1;
            for (int j = 0; j < FRAMES; j++)
            {
                if (frame[j] == -1)
                {
                    replaceIndex = j;
                    break;
                }
                if (rec[j] < min_rec)
                {
                    min_rec = rec[j];
                    replaceIndex = j;
                }
            }
            frame[replaceIndex] = pages[i];
            rec[replaceIndex] = ++time;
            r.pageFault++;
        }
        printf("\n %d \t\t", pages[i]);
        for (int ij = 0; ij < FRAMES; ij++)
        {
            if (frame[ij] == -1)
                printf(" - ");
            else
            {
                printf(" %d ", frame[ij]);
            }
        }
        if (found)
        {
            printf("\t\t\tHIT\n");
        }
        else
            printf("\t\t\tFAULT\n");
    }
    return r;
}
Result Optimal(int pages[], int n)
{
    int frame[FRAMES];
    for (int i = 0; i < FRAMES; i++)
        frame[i] = -1;
    Result r = {0, 0};
    printf("\n Page \t\tFrames\t\t\t Status \n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        // Condition of a HIT .
        int found = 0;
        for (int ij = 0; ij < FRAMES; ij++)
        {
            if (frame[ij] == pages[i])
            {
                r.pageHit++;
                found = 1;
                break;
            }
        }
        // Condition of Page Fault .
        if (!found)
        {
            int pageReplacement = -1;
            int farthest = i + 1;
            for (int ij = 0; ij < FRAMES; ij++)
            {
                if (frame[ij] == -1)
                {
                    pageReplacement = ij;
                    break;
                }
                int k;
                for (k = i + 1; k < n; k++)
                {
                    if (frame[ij] == pages[k])
                    {
                        break;
                    }
                }
                if (k == n)
                {
                    pageReplacement = ij;
                    break;
                }
                else
                {
                    if (k > farthest)
                    {
                        farthest = k;
                        pageReplacement = ij;
                    }
                }
            }
            frame[pageReplacement] = pages[i];
            r.pageFault++;
        }
        printf("\n %d \t\t", pages[i]);
        for (int ij = 0; ij < FRAMES; ij++)
        {
            if (frame[ij] == -1)
                printf(" - ");
            else
            {
                printf(" %d ", frame[ij]);
            }
        }
        if (found)
        {
            printf("\t\t\tHIT\n");
        }
        else
            printf("\t\t\tFAULT\n");
    }
    return r;
}
int main()
{
    int n, pages[MAX_PAGES];
    printf("Enter the total number of pages in the process: \n");
    scanf("%d", &n);
    printf("Enter the sequence of pages:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    Result opt = Optimal(pages, n);
    printResult("Optimal", opt, n);
    Result Lru = LRU(pages, n);
    printResult("LRU", Lru, n);
    Result Fifo = FIFO(pages, n);
    printResult("FIFO", Fifo, n);
    return 0;
}