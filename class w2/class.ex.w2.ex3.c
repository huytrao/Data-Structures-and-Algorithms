#include<stdio.h>

int binarySearch(int n, int arr[], double value) // thay doi kieu du lieu gia tri dau vao va mang
{
   int end = n - 1;
   int start = 0;
   
   while (1)
   {
      int mid = (end + start) / 2;
      
      if (arr[mid] > value)
      {
         end = mid - 1;
      }
      else if (arr[mid] < value)
      {
         start = mid + 1;
      }
      else if (arr[mid] == value)
      {
         return mid;
      }
      
      if (start >= end)
      {
         return -1;
      }
   }
}

int main()
{
    int arr[1000];
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    double value;
    scanf("%lf", &value); // in ra ket qua 
    int result = binarySearch(n, arr, value);
    
    if(result == -1)
    {
        printf("not found!");
    }
    else
    {
        printf("\n %d", result);
    }
    
    return 0;
}
