// Addition of array using two thread using dynamic memory allocation
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int *arr;
int sum1 = 0, sum2 = 0, n;
void *sum_1(void *arg)
{
    for (int i = 0; i < n / 2; i++)
    {
        sum1 += arr[i];
    }
    return NULL;
}
void *sum_2(void *arg)
{
    for (int i = n / 2; i < n; i++)
    {
        sum2 += arr[i];
    }
    return NULL;
}
int main()
{
    pthread_t t1, t2;
    printf("Enter the size of the array : \n");
    scanf("%d", &n);
    printf("Enter %d Elements one by one : \n", n);
    arr = (int *)malloc(n * (sizeof(int)));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    pthread_create(&t1, NULL, sum_1, NULL);
    pthread_create(&t2, NULL, sum_2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Sum of all array elemnents is %d \n", sum1 + sum2);
    return 0;
}