#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// huytrao on the coding 
//các hàm cần thiết
float average(float arr[], int n){
    float sum = 0;
    for (int i=0;i<n;i++)
    {
        sum += arr[i];
        return sum/n;
    }
}
void initializeArray(int arr[],int n, int min, int max){
    int i;
    srand(time(0));// khởi tạo seed cho hầm rand()dựa trên thời gian hiện tại.
    for(i =0;i<n;i++)
    {
        arr[i]=min + rand()% (max-min+1);
        // Sinh ngẫu nhiên giá trị trong khoảng [min,max]
    }
}
int minIndex(float arr[], int n)
{

}