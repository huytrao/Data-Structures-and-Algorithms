#include <stdio.h>
#include <time.h>

// Hàm hoán đổi giữa hai phần tử
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Tính step hàm bubble Sort
int bubbleSort(int arr[], int n) {
    int swaps = 0;
    int comps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int c = 0; c < n - i - 1; c++) {
            comps++;
            if (arr[c] > arr[c + 1]) {
                swaps++;
                swap(&arr[c], &arr[c + 1]);
            }
        }
    }

    return swaps + comps;
}

// Hàm chèn tính số bước
void selectionSort(int arr[], int n, int *selection_step) {
    (*selection_step) = 0;

    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            (*selection_step)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
            (*selection_step)++;
        }
    }
}

void insertionSort(int arr[], int n, int *insertion_step) {
    int comps = 0;
    int shift = 0;
    (*insertion_step) = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        (*insertion_step)++;
        while (j >= 0 && key < arr[j]) {
            comps++;
            shift++;
            arr[j + 1] = arr[j];
            j--;
        }
        if (j != 0) {
            comps++;
        }
        arr[j + 1] = key;
        (*insertion_step) = comps + shift;
    }
}

// Hàm phân hoạch
int partition(int arr[], int left, int right, int *shiftleft, int *shiftright, int *swaps) {
    int pivot = right;
    right--;

    while (1) {
        while (arr[left] <= arr[pivot] && left < pivot) {
            (*shiftleft)++;
            left++;
        }

        while (arr[right] >= arr[pivot] && right > left) {
            (*shiftright)++;
            right--;
        }

        if (left >= right) {
            break;
        } else {
            (*swaps)++;
            swap(&arr[left], &arr[right]);
        }
    }

    (*swaps)++;
    swap(&arr[left], &arr[pivot]);

    return left;
}

// Hàm quicksort
int quicksort(int arr[], int left, int right, int *steps) {
    if (left < right) {
        int shiftleft = 0;
        int shiftright = 0;
        int swaps = 0;

        int pivotIndex = partition(arr, left, right, &shiftleft, &shiftright, &swaps);
        (*steps) = shiftleft + shiftright + swaps;

        quicksort(arr, left, pivotIndex - 1, steps);
        quicksort(arr, pivotIndex + 1, right, steps);
    }
}

void Copy_arr(int arr[], int arr_cp[], int n) {
    for (int i = 0; i < n; i++) {
        arr_cp[i] = arr[i];
    }
}

void input_arr(int arr[], int *n) {
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < 4; i++) {
        int arr[100];
        int arr_cp[100];
        int n;
        input_arr(arr, &n);
        Copy_arr(arr, arr_cp, n);
        int se_step = 0;
        selectionSort(arr_cp, n, &se_step);
        Copy_arr(arr, arr_cp, n);
        int in_step = 0;
        insertionSort(arr_cp, n, &in_step);
        Copy_arr(arr, arr_cp, n);
        int q_steps = 0;
        quicksort(arr_cp, 0, n - 1, &q_steps);
        int bub_step = bubbleSort(arr, n);

        printf("\n");
        print_arr(arr, n);
        printf("\nBubble Sort step: %d", bub_step);
        printf("\nSelection Sort step: %d", se_step);
        printf("\nInsertion Sort step: %d", in_step);
        printf("\nQuick Sort step: %d\n", q_steps);
    }

    return 0;
}
