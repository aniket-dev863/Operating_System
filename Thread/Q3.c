#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int *arr;
int n;
void *print_square(void *arg)
{
    int index = *((int *)arg);
    printf("Square of %d : %d \n", arr[index], arr[index] * arr[index]);
    free(arg);
    return NULL;
}
int main()
{
    printf("Enter the number of elements :\n");
    scanf("%d", &n);
    printf("Enter %d Elements with a single space : \n", n);
    arr = (int *)malloc(n * (sizeof(int)));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    pthread_t t[n];
    for (int i = 0; i < n; i++)
    {
        int *index = malloc(sizeof(int));
        *index = i;
        pthread_create(&t[i], NULL, print_square, index);
    }
    for (int i = 0; i < n; i++)
    {
        pthread_join(t[i], NULL);
    }
    free(arr);
    return 0;
}