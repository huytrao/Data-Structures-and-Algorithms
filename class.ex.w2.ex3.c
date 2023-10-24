#include<stdio.h>

int binarySearch(int n,int arr[],int value)
{
   int end=n-1; // dat gia tri ban dau
   int start = 0;
   
   while(1)
   {
    int mid = (end + start)/2; // cat doi 
    
   if( arr[mid] > value) // kiem tra gia tri be hon khong neu co thi loai bo phan truoc
   {
        start = mid -1;
   }
   else if(arr[mid] < value)//  kiem tra  gia tri co be hon khong neu co loai bo phan truoc
   {
    end = mid +1;
   }
    else if(arr[mid]==value) // neu gia tri bang thi tra ve vi tri
    {
        return mid;
    }
    if(start>= end)// neu sai thi tra ve false
    {
        return -1;
    }
    
    }
}

int main()
{   int arr[1000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int value;
    scanf("%d",&value);
    if(binarySearch(n,arr,value) == -1)
    {
        printf("not found!");
    }else{
    printf("\n %d",binarySearch(n,arr,value));
    }
    return -1;
}