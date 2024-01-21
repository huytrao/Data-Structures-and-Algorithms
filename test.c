#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// hàm sinh mảng
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    } 
}
void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%5d",a[i]);
    printf("\n");
}

void insertZero(int a[], int *n, int position){
    (*n)++;
    for(int i = (*n) - 1; i > position; i--)
        a[i] = a[i-1];
    a[position] = 0;
}
void f(int a[], int *n, int *comps, int *swaps, int *insert) {
    (*comps) = 0;
    (*swaps) = 0;
    (*insert) = 0;
    int min = 0;
    int j;

    for (int i = 0; i < (*n); i++) {
        printf("i = %d\n", i);
        (*comps)++;

        if (i % 2 == 0) {
            for (j = i; j < (*n); j++) {
                (*comps)++;
                if (a[j] % 2 == 0) {
                    (*comps)++;
                    if (a[min] % 2 != 0) {
                        min = j;
                    } else {
                        (*comps)++;
                        if (a[min] > a[j] || min < i) {
                            min = j;
                        }
                    }
                }
            }

            (*comps)++;
            if (a[min] % 2 == 0) {
                (*swaps)++;
                swap(&a[i], &a[min]);
            } else {
                (*insert)++;
                insertZero(a, n, i);
            }
        } else {
            for (j = i; j < (*n); j++) {
                (*comps)++;
                if (a[j] % 2 != 0) {
                    (*comps)++;
                    if (a[min] % 2 == 0) {
                        min = j;
                    } else {
                        (*comps)++;
                        if (a[min] > a[j] || min < i) {
                            min = j;
                        }
                    }
                }
            }

            (*comps)++;
            if (a[min] % 2 != 0) {
                (*swaps)++;
                swap(&a[i], &a[min]);
            } else {
                (*insert)++;
                insertZero(a, n, i);
            }
        }

        printArray(a, *n);
    }
}

void Average(int arr[], int n, int k, int fre_comps[], int fre_swaps[], int fre_inserts[], float *sum_comps, float *sum_swaps, float *sum_insert)
{
    int min = -n * 10;
    int max = n * 10;
    initializeArray(arr, n, min, max);
    (*sum_comps) = 0;
    (*sum_swaps) = 0;
    (*sum_insert) = 0;

    int comps, swaps, inserts;
    for (int i = 0; i < k; i++)
    {
        comps = 0;
        inserts = 0;
        swaps = 0;
        f(arr, &n, &comps, &swaps, &inserts);
        fre_comps[comps]++;
        fre_inserts[inserts]++;
        fre_swaps[swaps]++;
        (*sum_comps) += comps;
        (*sum_swaps) += swaps;
        (*sum_insert) += inserts;
    }

    (*sum_comps) /= k;
    (*sum_insert) /= k;
    (*sum_swaps) /= k;
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int arr[20], n = 20;
    int k[5] = {10,20,100,1000,10000};
    for (int i=0; i<5;i++)
    {
        printf("k=%d \n", k[i]);
        int fre_comps[21] = {0};
        int fre_swaps[21] = {0};
        int fre_inserts[21] = {0};
        float avg_comps =0;
        float avg_swaps =0;
        float avg_inserts =0;
        Average(arr, n, k[i], fre_comps,fre_swaps,fre_inserts,&avg_comps,&avg_swaps,&avg_inserts);
        for (int j = 1; j <= 20; j++)
            printf("%d ", j);
        printf("\n");
        printf("comps:");
        for (int j = 1; j <= 20; j++)
            printf("%d ", fre_comps[j]);
        printf("\n");
        printf("swaps:");
        for (int j = 1; j <= 20; j++)
            printf("%d ", fre_swaps[j]);
        printf("\n");
        printf("inserts:");
        for (int j = 1; j <= 20; j++)
            printf("%d ", fre_swaps[j]);
        printf("\nAverage comps: %0.3f\n", avg_comps);
        printf("\nAverage swaps: %0.3f\n", avg_swaps);
        printf("\nAverage inserts: %0.3f\n", avg_inserts);
    }
    return 0;
}