#include <stdio.h>
#include <stdlib.h>


void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    } 
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

void insertionSort(int arr[], int n, int *insertion_step)
{
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

int main()
{
    int n = 20;
    int arr[10] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int bu_step = 0;
    int in_step = 0;
    int se_step = 0;

    int arr_bu[10], arr_in[10], arr_se[10];
    for (int i = 0; i < n; i++)
    {
        arr_bu[i] = arr[i];
        arr_in[i] = arr[i];
        arr_se[i] = arr[i];
    }

    bubbleSort(arr_bu, n, &bu_step);
    insertionSort(arr_in, n, &in_step);
    selectionSort(arr_se, n, &se_step);

    printf("\n Arr: ");
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr_bu[i]);
    }
    printf("\nSelection sort steps: %d", se_step);
    printf("\nInsertion sort steps: %d", in_step);
    printf("\nBubble sort steps: %d", bu_step);

    return 0;
}
