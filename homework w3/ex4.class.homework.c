#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// huytrao on the coding
//hàm tạo mảng
void initializeArray(int arr[], int n, int min, int max) {
    //them random n phan tu vao mang
    for (int i = 0; i < n; i++) {  
        arr[i] = min + rand() % (max - min + 1);
    } 
}
void delete(int a[], int *n, int index, int * assignment)
{
    (*assignment) =0;
    if(index < 0 || index >(*n)-1)
    {
        return;
    }
    for (int i = index; i<(*n)-1;i++)
    {
    (*assignment) ++;
     a[i]=a[i+1];
    }
}
int main()
{ 
    int n;
    int arr[22];
    int k[5] = {10,20,100,1000,10000};
    int max  = n*5;
    int min = -n*5;
    int assignment=0;
    int index;
    int fre[6][21] = {0};
    float avg[6] = {0};
    n=20;

    // thực hiện theo các tầng số
    for(int i=0;i<5;i++)
    {
        // chạy các mốc 10 20 100 1000 10000
        for(int j=0;j<k[i];j++)
        {   // reset lại giá trị n = 20
            n=20;
            // gián giá trị value từ 0 đến n;
            index=rand() % n;
            // khởi tạo mảng.
            initializeArray(arr,n,min,max);
            // thực thi hàm insert.
            delete(arr,&n,index,&assignment);
            // tính số lần insert trong mỗi vị trí.
            fre[i][index]++;
            // tính trung bình số bước;
            avg[i] = avg[i] + assignment;
        }
        printf("insert: %0.3f",avg[i]);
        avg[i] /= k[i];
    }
    for(int i=0;i<5;i++)
    {   printf("k= %d \n",k[i]);
        for(int j=0;j<=20;j++)
        {
            printf(" %d", j);
        }
        printf("\n");
        for(int j=0;j<=20;j++)
        {
            printf(" %d", fre[i][j]);
        }
        printf("\n");
        printf("avg: %0.3f",avg[i]);
        printf("\n");
    }
}