#include <stdio.h>
void insertionSort(int arr[], int n)   // hàm insertion sort
{
    for (int i = 1; i < n;i++)
    {
        int pos = i, key = arr[i];
        while (arr[pos-1] >= key && pos>0)
        {
            arr[pos] = arr[pos - 1];
            pos--;
        }
        if (i != pos)
            arr[pos] = key;
    }
}
int main()
{
    
}