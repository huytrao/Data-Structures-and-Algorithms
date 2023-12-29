#include <stdio.h>
#include <stdlib.h>

//hàm sinh mảng

void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    } 
}
// hàm chuyển đổi vị trí
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// hàm nỗi bọt
void bubbleSort(int arr[], int n, int *bubble_step)
{
    (*bubble_step) = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            (*bubble_step)++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                (*bubble_step)++;
            }
        }
    }
}
// thuật toán insertionsort
void insertionSort(int arr[], int n, int *insertion_step)
{
    // shift + comps
    (*insertion_step) =0;
    int comps = 0;
    int shift = 0;
    (*insertion_step) = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        (*insertion_step)++;
        while (j >= 0 && key < arr[j])
        {
            comps++;
            shift++;
            arr[j + 1] = arr[j];
            j--;
        }
        if (j != 0)
        {
            comps++;
        }
        arr[j + 1] = key;
        (*insertion_step) = comps + shift;
    }
}

void selectionSort(int arr[], int n, int *selection_step)
{
    (*selection_step) = 0;

    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            (*selection_step)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            swap(&arr[min_idx], &arr[i]);
            (*selection_step)++;
        }
    }
}
void average(int arr[],int n[])
{   
    int bu_step,in_step,se_step;
    float avg_bu =0;
    float avg_in =0;
    float avg_se =0;
    int k = 100000;
    printf("repeat %d lần\n",k);
    printf("n| BubbleSort | InsertionSort | SelectionSort \n");
    for(int i=0;i<4;i++)
    {
        
        for(int j=0;j<k;j++){
            bu_step=0;
            in_step=0;
            se_step=0;
            initializeArray(arr,n[i],-100,100);
            selectionSort(arr,n[i],&se_step);
            avg_se +=se_step;
            initializeArray(arr,n[i],-100,100);
            bubbleSort(arr,n[i],&bu_step);
            avg_bu += bu_step;
            initializeArray(arr,n[i],-100,100);
            insertionSort(arr,n[i],&in_step);
            avg_in +=in_step;
        }
        avg_bu /= k;
        avg_in /=k;
        avg_se /=k;
        printf("%d |",n[i]);
        printf("%0.3f    %0.3f  %0.3f    \n",avg_bu,avg_in,avg_se);
    }
}
int main()
{
    int arr[200];
    int n[4] = {10,20,50,100};
    average(arr,n);
   return 0;
}
