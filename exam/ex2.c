#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void f(int a[], int n, int *comps, int *assigns) {
    *assigns = 0;
    *comps = 0;
    int t;
    for (int i = 0; i < n - 1; i++) {
        (*comps)++;
        if (a[i] % 2 != 0) {
            for (int j = i + 1; j < n; j++) {
                (*comps)++;
                (*comps)++;
                if (a[j] % 2 != 0 && a[i] > a[j]) {
                    (*assigns)++;
                    t = a[i];
                    (*assigns)++;
                    a[i] = a[j];
                    (*assigns)++;
                    a[j] = t;
                }
            }
        }
    }
}

void Average(int arr[], int n, int k, int fre_comps[], int fre_assigns[], float *sum_comps, float *sum_assigns) {
    int min = -n * 10;
    int max = n * 10;
    *sum_comps = 0;
    *sum_assigns = 0;

    int comps, assigns;
    for (int i = 0; i < k; i++) {
        initializeArray(arr, n, min, max);
        comps = 0;
        assigns = 0;
        f(arr, n, &comps, &assigns);
        fre_comps[comps]++;
        fre_assigns[assigns]++;
        *sum_comps += comps;
        *sum_assigns += assigns;
    }

    *sum_comps /= k;
    *sum_assigns /= k;
}

int main(void) {
    time_t t;
    srand((unsigned)time(&t));
    // khai báo biến 
    int arr[20], n = 10;
    // khai báo biến k
    int k[3]= {100, 1000, 10000};
    printf("k=%d \n", n);

    // Move the initialization outside the loop
    int fre_comps[11] = {0};
    int fre_assigns[11] = {0};

    for(int i=0;i<3;i++) {
        float avg_comps = 0;
        float avg_assigns = 0;
        // thực hiện tính bảng tần số
        Average(arr, n, k[i], fre_comps, fre_assigns, &avg_comps, &avg_assigns);
        // in bảng tần số
        printf("%d\n",k[i]);
        for (int j = 1; j <= n; j++)
            printf("%d ", j);
        printf("\n");
        printf("comps: ");
        for (int j = 1; j <= n; j++)
            printf("%d ", fre_comps[j]);
        printf("\n");
        printf("assigns: ");
        for (int j = 1; j <= n; j++)
            printf("%d ", fre_assigns[j]);
        printf("\n");
        printf("\nAverage comps: %0.3f\n", avg_comps);
        printf("\nAverage assigns: %0.3f\n", avg_assigns);
    }
    return 0;
}
