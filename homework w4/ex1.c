#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializeArray(int arr[], int n, int min, int max) {
    int i;
    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void bubbleSort(int array[], int n, int *comps, int *swaps, int frecomps[], int freswaps[]) {
    (*comps) = 0;
    (*swaps) = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            (*comps)++;
            if (array[j] < array[i]) {
                (*swaps)++;
                int temp;
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        frecomps[i] += *comps;
        freswaps[i] += *swaps;
    }
}

void avg(int arr[], int k[], int n) {
    float freswaps[100] = {0};
    float frecomps[100] = {0};
    float avgcomps[100] = {0};
    float avgswaps[100] = {0};
    int comps = 0;
    int steps = 0;

    for (int i = 0; i < n; i++) {
        printf("\nk=%d\n", k[i]);
        for (int j = 0; j < k[i]; j++) {
            bubbleSort(arr, n, &comps, &steps, frecomps, freswaps);
        }
        for (int c = 0; c < n; c++) {
            avgcomps[c] += frecomps[c];
            avgswaps[c] += freswaps[c];
        }
    }
    for (int c = 0; c < n; c++) {
        avgcomps[c] /= k[c];
        avgswaps[c] /= k[c];
    }

    printf("Observation =");
    for (int j = 0; j < n; j++) {
        printf(" %d", j);
    }
    printf("\ncomps= ");
    for (int j = 0; j < n; j++) {
        printf(" %0.3f", avgcomps[j]);
    }
    printf("\nswaps= ");
    for (int j = 0; j < n; j++) {
        printf(" %0.3f", avgswaps[j]);
    }
}

int main() {
    int arr[100];
    int n;
    int k[6] = {0, 25, 50, 100, 1000, 10000};
    scanf("%d", &n);
    int min = -20 * n;
    int max = 20 * n;
    initializeArray(arr, n, min, max);
    avg(arr, k, n);

    return 0;
}
