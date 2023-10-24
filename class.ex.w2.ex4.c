#include <stdio.h>

int binarySearch(int n,int arr[],int value)
{
   int end=n-1; // dat gia tri ban dau
   int start = 0;
   int dem =0;
   while(1)
   {
    dem++;
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
        if(arr[mid+1]== value)
        {
        return dem +2; // tra ve dem + 2
        }
        else
        {
            return dem +1;
        }
    }
    if(start>= end)// neu sai thi tra ve false
    {
        return dem+1;
    }
    
    }
}


int linearSearch(int n, int arr[],int value) // ham tim kiem tuyen tinh trong order arr
{
    for(int i=0;i<n;i++) // quet tung phan tu trong mang tu vi tri 0
    {
        if(arr[i]==value) // so sanh cac phan tu neu trung tra ve vi tri step 
        {
            return i +1 ;
        }
    }
    return n; // sai tra ve false
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
    printf("\n steplinear : %d",linearSearch(n,arr,value));
    printf("\n stepbinary : %d",binarySearch(n,arr,value));
    return -1;
}
