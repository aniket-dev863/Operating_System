// Write a C program to implement the sum of array using 2 threads.
#include <stdio.h>
#include <pthread.h>
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum1 = 0, sum2 = 0;
void *sum_1(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        sum1 += arr[i];
    }
    return NULL;
}

void *sum_2(void *arg)
{
    for (int i = 5; i < 10; i++)
    {
        sum2 += arr[i];
    }
    return NULL;
}
int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, sum_1, NULL);
    pthread_create(&t2, NULL, sum_2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Sum of the array : %d \n", sum1 + sum2);
    return 0;
}
