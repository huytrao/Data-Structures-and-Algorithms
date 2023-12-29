#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int arr[], int n, int min, int max) { // ham tim 
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    } 
}
int linearSearch(int arr[], int n, int value, int*comps)
{
    *comps=0;
    for (int i=0; i<n; i++)
    {
        (*comps)++;
        if (arr[i] == value)
            return i;
    }
    return -1;
}
float Average(int arr[], int n, int k, int fre[])
{
    int min = -n*10;
    int max = n*10;
    initializeArray(arr, n, min, max);
    float sum = 0;
    for (int i=0; i<k; i++)
    {
        int value = arr[rand() % 20];//phần từ bất kỳ thuộc mảng.
        int comps;
        linearSearch(arr, n, value, &comps);
        fre[comps]++;
        sum += comps;
    }
    return sum / k;
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int arr[20], n = 20;
    int k[5] = {10,20,100,1000,10000};
    for (int i=0; i<5;i++)
    {
        printf("k=%d \n", k[i]);
        int fre[21] = {0};
        float A=Average(arr, n, k[i], fre);
        for (int j = 1; j <= 20; j++)
            printf("%d ", j);
        printf("\n");
        for (int j = 1; j <= 20; j++)
            printf("%d ", fre[j]);
        printf("\nAverage: %0.3f\n", A);
    }
    return 0;
}