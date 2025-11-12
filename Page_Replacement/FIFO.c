#include <stdio.h>
int main()
{
    int frames[4];
    int pages[50];
    int f_c = 4;
    int p_c;
    int pageFaults = 0, pageHits = 0;
    int nextReplace = 0;
    for (int i = 0; i < f_c; i++)
    {
        frames[i] = -1;
    }
    printf("Enter the total number of pages: \n");
    scanf("%d", &p_c);
    printf("Enter the %d pages space separated :\n", p_c);
    for (int i = 0; i < p_c; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("\n Page \t\tFrames\t\t\t Status \n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < p_c; i++)
    {
        int currentPage = pages[i];
        int found = 0;
        for (int ij = 0; ij < f_c; ij++)
        {
            if (currentPage == frames[ij])
            {
                found = 1;
                pageHits++;
                break;
            }
        }
        if (!found)
        {
            pageFaults++;
            frames[nextReplace] = currentPage;
            nextReplace = (nextReplace + 1) % f_c;
        }
        printf("%d\t\t", currentPage);
        for (int ij = 0; ij < f_c; ij++)
        {
            if (frames[ij] == -1)
                printf(" - ");
            else
                printf(" %d ", frames[ij]);
        }
        if (found)
        {
            printf("\t\t\t HIT \n");
        }
        else
            printf("\t\t\t FAULT \n");
    }
    return 0;
}