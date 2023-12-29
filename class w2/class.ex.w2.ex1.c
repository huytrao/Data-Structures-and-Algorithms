#include <stdio.h>

void Insertvalue(float arr[], float value, int pos, int *n) {
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void insertOrderedArray(float arr[], int *n, float value) {
    if (arr[0] >= value) {
        Insertvalue(arr, value, 0, n);
    } else {
        for (int i = 1; i < *n; i++) {
            if (value <= arr[i]) {
                Insertvalue(arr, value, i, n);
                break;
            }
            if (i == *n - 1) {
                arr[*n] = value;
                (*n)++;
                break;
            }
        }
    }
}

int main() {
    float arr[1000];
    int n; // Changed from float to int
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float value;
    scanf("%f", &value);

    insertOrderedArray(arr, &n, value);

    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }

    return 0;
}
