#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    *a = *b + *a;
    *b = *a -*b;
    *a = *a-*b;
}
int partion(int arr[],int left,int right, int *shiftleft,int *shiftright)
{
    int shiftleft
    int pivot = right;
    right --;
    while(1)
    {
        while(arr[left]<=arr[pivot]&& left<pivot)
            
            left ++;
        while(arr[right] >= arr[pivot]&& right >0)
        if(left >= right)
            break;
        else
            swap(arr+ left, arr+ pivot);
    }
    swap(arr + left, arr + pivot);
    return left;
}

			
void quicksort(int arr[],int left,int right)
{
 
    if(right <= left)
        return;
    else{
        int pivot = partition(arr,left,right);
        quicksort(arr,left,pivot -1);
        quicksort(arr, pivot+1,right);
    }
}
int print_arr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int input_arr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}


int main()
{
    int arr[100];
    int n;
    scanf("%d",&n);
    input_arr(arr,n);
    int d = partion(arr,0,5);
    printf("\n%d",d);
}

