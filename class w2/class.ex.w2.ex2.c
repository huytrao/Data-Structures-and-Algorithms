#include <stdio.h>

int linearSearch(int n, int arr[],int value) // ham tim kiem tuyen tinh trong order arr
{
    for(int i=0;i<n;i++) // quet tung phan tu trong mang tu vi tri 0
    {
        if(arr[i]==value) // so sanh cac phan tu neu trung tra ve vi tri
        {
            return i;
        }
    }
    return -1; // sai tra ve false
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
    if(linearSearch(n,arr,value) == -1)
    {
        printf("not found!");
    }else{
    printf("\n %d",linearSearch(n,arr,value));
    }
    return -1;
}