#include <stdio.h>
#include <stdlib.h>
// tạo mảng số nguyên
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        // random hàm sinh mảng
        arr[i] = min + rand() % (max - min + 1);
    } 
}
void swap(int *a, int *b)
{
    // hoán vị 2 vị trí
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
  // chạy số lượt phần tử
    for (int i = 0; i < n; i++)
    {
        // vòng lặp 
        for (int j = 0; j < n - i -1; j++)
        {
            // so sánh nếu phần tử trước lớn hơn phần tử sau thì hoán vị
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    // chạy vòng lặp c++
    for (int i = 1; i < n; i++)
    {   
        // đặt key là arr ở vị trí  i để thực hiện so sánh ở phần tử phía sau
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key > arr[j])
        {
            // thực hiện dời phần tử nếu thỏa điêu kiện
            arr[j + 1] = arr[j];
            // giảm j xuống một đơn vị
            j--;
        }
        // đặt a[j] bằng key
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, max_idx;
    for (i = 0; i < n - 1; i++)
    {
        // đặt biến khởi tạo max tại vị trí ban đầu
        max_idx = i;
        for (j = i + 1; j < n; j++)
        {
            // so sanh giá trị của biến
            if (arr[j] > arr[max_idx])
                max_idx = j;
        }
        if (max_idx != i)
        {
            // hoán vị hai vị trí giữa max idx với arr[i]
            swap(&arr[max_idx], &arr[i]);
        }
    }
}

int main()
{
    int n = 20;
    int arr_bu[20], arr_in[20], arr_se[20];
    // tạo mảng
    initializeArray(arr_in,n,-20*n,20*n);
    initializeArray(arr_bu,n,-20*n,20*n);
    initializeArray(arr_se,n,-20*n,20*n);
    // thực hiện các phương pháp sắp xếp
    bubbleSort(arr_bu, n);
    insertionSort(arr_in, n);
    selectionSort(arr_se, n);
    // in kết quả
    printf("\n Arr_bu: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr_bu[i]);
    }
    printf("\n Arr_in: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr_in[i]);
    }
    printf("\n Arr_se: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr_se[i]);
    }
    return 0;
}
