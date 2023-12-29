#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// hàm sinh mảng ngẫu nhiên int
void randarr(int arr[], int n, int min, int max) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        // gán giá trị ngẫu nhiên cho mảng
        arr[i]= min + rand()%(max-min+1);
    }
}
// thuật toán sắp xếp.
void bubbleSort(int arr[],int n, int *swaps, int *comparison)
{  // thực hiện so sánh
    *comparison =0;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {   // tăng lên 
           ( *comparison) ++;
           // so sanh gia trị j có nhỏ hơn gia trị j-1 không
            if(arr[j-1] > arr[j]){
                // hoán đổi vị trí
                *swaps = arr[j-1];
                arr[j-1]=arr[j];
                arr[j]= *swaps;
            }
        }
    }
}
int main()
// khai báo biến
{   int comparison =0;
    int swaps=0;
    int arr[1000];
    // tạo mảng 
    int n[10]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    // thực hiện in 
    printf("n=");
    for(int i=0;i<10;i++)
    {
        printf(" %d",n[i]);
    }
    printf("\n");
    printf("comparision:");
    for(int i=0;i<10;i++)
    {   float sum=0;
    // thực hiện chạy với các n
            randarr(arr,n[i],-100,100);
            bubbleSort(arr,n[i],&swaps,&comparison);
            printf(" %d",comparison);
    }
}