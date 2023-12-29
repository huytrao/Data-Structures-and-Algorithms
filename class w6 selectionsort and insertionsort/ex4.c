#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}
void selectionSort(int arr[], int n, int *comps, int *swaps)
{
    int i, j, min_idx;
    // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
    for (i = 0; i < n - 1; i++)
    {
        // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            (*comps)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        swap(&arr[min_idx], &arr[i]);
        (*swaps)++;
    }
    if(min_idx !=1) {
        swap(&arr[min_idx],&arr[i]);
        *swap += 1;
    }
}

void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    } 
}

// ham insertion sort
void insertionSort(int arr[], int n, int *comps, int *shift)
{
    (*comps) = 0;
    (*shift) = 0;
    int i, key, j;
    for (i = 0; i < n; i++)
    {
        // đặt biến tạm để chạy vòng lặp
        key = arr[i];
        //đặt biến đếm j để lọc các phần tử lơn hơn
        j = i - 1;
        // chạy vòng lặp
        while (j >= 0 && key < arr[j])
        {
            (*comps)++;
            // gán biến lùi về một đơn vị
            (*shift)++;
            arr[j + 1] = arr[j];
            // lùi gái trị key về một đơn vị nếu nó bé hơn
            arr[j] = key;
            j--;
        }
        // trường hợp vào so sánh không thỏa khi trong vòng while để tăng comps()
        if (j != 0)
        {
            (*comps)++;
        }
    }
}

void Average_insert(int arr[], int n, int k, int fre_shift[],int fre_comps[],float *sum_comps,float *sum_shifts)
{   
    int min = -n*10;
    int max = n*10;
    *sum_comps = 0;
    *sum_shifts = 0;
    for (int i=0; i<k; i++)
    {
        initializeArray(arr, n, min, max);
        //phần từ bất kỳ thuộc mảng.
        int comps,shift;
        insertionSort(arr,n,&comps,&shift);
        fre_comps[comps]++;
        fre_shift[shift]++;
        (*sum_comps) += comps;
        (*sum_shifts) +=shift;
    }
    (*sum_comps) = (*sum_comps)/k;
    (*sum_shifts) = (*sum_shifts)/k;
}
void Average_select(int arr[], int n, int k, int fre_shift[],int fre_comps[],float *sum_comps,float *sum_shifts)
{   
    int min = -n*10;
    int max = n*10;
    *sum_comps = 0;
    *sum_shifts = 0;
    for (int i=0; i<k; i++)
    {
        initializeArray(arr, n, min, max);
        //phần từ bất kỳ thuộc mảng.
        int comps,shift;
        selectionSort(arr,n,&comps,&shift);
        fre_comps[comps]++;
        fre_shift[shift]++;
        (*sum_comps) += comps;
        (*sum_shifts) +=shift;
    }
    (*sum_comps) = (*sum_comps)/k;
    (*sum_shifts) = (*sum_shifts)/k;
}

void main(){
    int fre_shift[11]={0};
    int fre_comps[11]={0};
    float avg_shift =0;
    float avg_comps =0;
    int comps = 0;
    int shift=0;
	int n = 10;
	int arr[5] = {12, 11, 13, 5, 6};
    // thực thi hàm
    int k[2]= {1000, 10000};
    for (int i=0; i<2;i++)
    {
        printf("k=%d \n", k[i]);
        Average_insert(arr, n, k[i],fre_shift, fre_comps,&avg_comps,&avg_shift);
        printf("pos:");
        for (int j = 1; j <= 10; j++)
            printf("%d ", j);
        printf("\n");
        printf("comps:");
        for (int j = 1; j <= 10; j++)
            printf("%d ", fre_comps[j]);
        printf("\n");
        printf("shift:");
        for (int c = 1; c <= 10; c++)
            printf("%d ", fre_shift[c]);   
    printf("\nsum Average: %0.3f \n",avg_comps + avg_shift);

   
   
    
    }
     printf("\nselection sort\n");
    int fre_comps1[11]={0};
    int fre_swap[11]={0};
    float avg_swap =0;
    float avg_comps1 =0;
    for (int i=0; i<2;i++)
    {
        printf("k=%d \n", k[i]);
        Average_select(arr, n, k[i], fre_comps1,fre_swap,&avg_comps1,&avg_swap);
        printf("pos:");
        for (int j = 1; j <= 10; j++)
            printf("%d ", j);
        printf("\n");
        printf("comps:");
        for (int j = 1; j <= 10; j++)
            printf("%d ", fre_comps1[j]);
        printf("\n");
        printf("swap:");
        for (int c = 1; c <= 10; c++)
            printf("%d ", fre_swap[c]);   
    printf("\nsum Average: %0.3f \n",avg_comps1 + avg_swap);
     }
}