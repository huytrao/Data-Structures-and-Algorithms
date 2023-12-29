#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initializeArray(int arr[],int n, int min, int max){
    int i;
    srand(time(0));// khởi tạo seed cho hầm rand()dựa trên thời gian hiện tại.
    for(i =0;i<n;i++)
    {
        arr[i]=min + rand()% (max-min+1);
        // Sinh ngẫu nhiên giá trị trong khoảng [min,max]
    }
}
int main()

{ 
    int n=5;
    int arr[100];
     int max = 50;
    int min =0;
    time_t t;
    srand((unsigned)time(&t));
    printf("\n");
    initializeArray(arr,n,min,max);
    for(int i=0;i<n;i++)
    {
        printf("\n %d",arr[i]);
    }
}