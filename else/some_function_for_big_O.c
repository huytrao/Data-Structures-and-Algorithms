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
// hàm swap 
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
// hàm average 
float average(int arr[], int n){
    float sum = 0;
    for (int i=0;i<n;i++)
    {
        sum += arr[i];
        return sum/n;
    }
}
int linearSearch(int arr[], int n, int value)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==value)
        {
            return i;
        }
    }
    return -1;
}
// Binary Search 
int binarySearch(int arr[], int n, int value)
{
    int midPoint;
    int lowerBound = 0;
    int upperBound = n-1;
    while(lowerBound < upperBound) {
        midPoint = (lowerBound + upperBound)/2;
        if(value < arr[midPoint]){
            upperBound = midPoint -1;
        }
        else if (value > arr[midPoint])
        {
            lowerBound = midPoint +1;
        }
        else if(value == arr[midPoint]) {
            return midPoint;
        }
    }
    return -1;
}