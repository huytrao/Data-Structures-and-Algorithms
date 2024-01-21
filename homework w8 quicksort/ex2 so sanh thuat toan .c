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
    // khai báo biến
    int i, j, min_idx;
    // cho chạy vòng lặp
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            (*selection_step)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // so sánh giá trị 
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
            (*selection_step)++;
        }
    }
}
// thuật toán insertion sort
void insertionSort(int arr[], int n, int *insertion_step) {
    int comps = 0;
    int shift = 0;
    (*insertion_step) = 0;
    // chạy vòng lặp 
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        (*insertion_step)++;
        // chạy vòng while kvaf kiểm tra
        while (j >= 0 && key < arr[j]) {
            comps++;
            shift++;
            arr[j + 1] = arr[j];
            j--;
        }
        // xét trường hợp vẫn còn  phần tử thì ococng j thêm một lần so sánh
        if (j != 0) {
            comps++;
        }
        // tiến hành in seert key
        arr[j + 1] = key;
        (*insertion_step) = comps + shift;
    }
}
// hàm phân mảnh cho quicksort
int partition(int arr[], int left, int right, int *step) {
    int shift_right = 0;
    int shift_left = 0;
    int swaps = 0;
    int pivot = right;
    right--;
    // chạy hàm whwile kiểm ra điều kiền
    while (left < right) {
        while (arr[left] <= arr[pivot] && left < pivot) {
            shift_left++;
            left++;
        }

        while (arr[right] >= arr[pivot] && right > left) {
            shift_right++;
            right--;
        }

        if (left < right) {
            swaps++;
            swap(&arr[left], &arr[right]);
        }
    }

    swaps++;
    swap(&arr[left], &arr[pivot]);
    *step = swaps + shift_right + shift_left;
    return left;
}

// Hàm quicksort
void quicksort(int arr[], int left, int right, int *steps) {
    if (left < right) {
        int step =0;
        // thực hiện đặt pivot và thực hiện quick sort
        int pivotIndex = partition(arr, left, right, &step);
        (*steps) += step;

        quicksort(arr, left, pivotIndex - 1, steps);
        quicksort(arr, pivotIndex + 1, right, steps);
    }
}
// tiến hành copy mảng vào 
void Copy_arr(int arr[], int arr_cp[], int n) {
    for (int i = 0; i < n; i++) {
        arr_cp[i] = arr[i];
    }
}

// hàm nhập mảng
void input_arr(int arr[], int *n) {
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}
// hàm in mảng
void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    for (int i = 0; i < 4; i++) {
        // thực thi mảng
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
        int *q_steps;
        (*q_steps) =0;
        quicksort(arr_cp, 0, n - 1, q_steps);
        int bub_step = bubbleSort(arr, n);

        printf("\n");
        print_arr(arr, n);
        printf("\nBubble Sort step: %d", bub_step);
        printf("\nSelection Sort step: %d", se_step);
        printf("\nInsertion Sort step: %d", in_step);
        printf("\nQuick Sort step: %d\n", (*q_steps));
    }

    return 0;
}
