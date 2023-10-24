#include <stdio.h>
// huytrao on the coding

int SearchArr(float arr[][3], float value[3], int n,int count[]) // ham tim vi tri cua tat ca cac mang trung voi gia tri
{
    int dem =0;
    for(int i=0;i<n;i++)
    {
        if(value[0]== arr[i][0] && value[1]== arr[i][1]) 
        {
            count[dem] =i; // luu index cua vi tri trung vao mang count
            dem ++;
        }
    
    }
    return dem; //tra ve so luong
}
int Del_Ser_Arr(float arr[][3],float value[3], int *n)  // xoa Array
{
        int count[100];
        if(SearchArr(arr,value,*n,count) == 0) // dung tra ve xem thu gia tri value co ton tai trong mang khong
        {
            return -1;
        }
        else{
        int temp = SearchArr(arr,value,*n , count);// thuc thi mang
        int dem =0;
        for(int i = (count[dem] - dem); i<*n;i++) // thuc hien xoa bo tung phan tu trung trong mang
        {
        {
            arr[i][0] = arr[i+1][0];
            arr[i][1] =arr[i+1][1];
        }
        (*n)--;
        dem ++;
        }
        return 0;
    }
}
int main() {
    int n;
    float arr[100][3];
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<2;j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }
    float value[3];
    for(int i=0;i<2;i++)
    {
        scanf("%f",&value[i]);
    }
   int bool = Del_Ser_Arr(arr, value, &n); // thuc thi mang
    if(bool==-1) // in gia tri neu co ton tai trong amng
    {
        printf("Cannot delete %f %f from the array! ",value[0], value[1]);
    }else{
        for(int i=0;i<n;i++)
        {
            printf("\n%f %f  ",arr[i][0],arr[i][1]);
        }
    }

    return 0;
}
