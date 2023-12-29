#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// hàm selection short
void selectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {   
        int min_index =i; // đặt giá trị index min ở vị trí i
        for(int j=i+1;j<n;j++)
        {
            // so sánh nếu nhỏ hơn thì gắn lại min index
            if(arr[j]<arr[min_index])
            {
                min_index =j;
            }
        }
        // đổi chổ giá trị nhỏ nhất về vị trí i
        int temp = arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;

    }
}
int main()
// hàm sinh mảng
{   srand(time(NULL));
    int arr[100];
    int n=10;
    for (int i=0;i<n;i++)
    {
       // công thức sinh mảng
        arr[i] = -100 + rand()%(201);
    }
    selectionSort(arr,n);
    for(int i=0;i<n;i++)
    {
        // in ra kết quả đúng
        printf(" %d",arr[i]);
    }

}