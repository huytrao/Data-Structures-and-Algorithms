#include <stdio.h>

void Insertvalue(int arr[],int value, int pos,int *n)// ham insert
{
    for(int i=*n;i> pos;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos]=value;
    (*n)++;
}
void insertOrderedArray(int arr[], int *n, int value) // ham insert value 
{// chia cac truong hop 
    if(arr[0] >= value) // truong hop gia tri dau lon hon vlaue
    {
        Insertvalue(arr,value,0,n); 
    }
    else{
    for(int i=1;i<*n;i++)
    {
        if(value<=arr[i]) // cac phan tu dang xet nho hon value
        {
            Insertvalue(arr,value,i,n);
            break;
        }
        if(i==*n-1) // o cuoi mang thi chen luon
        {
            arr[*n]=value ;
            (*n)++;
            break;
        }
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
    insertOrderedArray(arr,&n,value);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}