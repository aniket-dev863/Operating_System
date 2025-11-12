// C program to compute factorial on numbers with n threads .
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int n;
int *arr;
int factorial(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}
void *printFact(void *arg)
{
    int index = *((int *)arg);
    printf("Factorial of %d is %d \n", arr[index], factorial(arr[index]));
    free(arg);
    return NULL;
}
int main()
{
    printf("Enter the number of elements :\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * (sizeof(int)));
    printf("Enter %d number of Elements: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    pthread_t t[n];
    for (int i = 0; i < n; i++)
    {
        int *index = malloc(sizeof(int));
        *index = i;
        pthread_create(&t[i], NULL, printFact, index);
    }
    for (int i = 0; i < n; i++)
    {
        pthread_join(t[i], NULL);
    }
    free(arr);
    return 0;
}
