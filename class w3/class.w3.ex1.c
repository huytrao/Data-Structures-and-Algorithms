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
// hàm average 
float average(int dem[], int n){
    float sum = 0;
    for (int i=0;i<n;i++)
    {
        sum = dem[i]*i;
        return sum/n;
    }
}

int main()
{
    int dem[20] = {0};
    int arr[20];
    int k;
    scanf("%d",k);
    initializeArray(arr,20,20*5,-20*5);

    for(int i=0;i<k;i++)
    {   int value =  arr[rand()% (20-0+1)];
        linearSearch (arr, 20, value, &dem[i] );
    }
    for(int i=0;i<20;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
      for(int i=0;i<20;i++)
    {
        printf("%d ",dem[i]);
    }
    printf("\n");
    printf("average:%f", average(dem,2);
}