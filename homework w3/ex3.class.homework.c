#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// huytrao on the coding
// ham tao mang
void initializeArray(int arr[], int n, int min, int max) {
    //them random n phan tu vao mang
    for (int i = 0; i < n; i++) {  
        arr[i] = min + rand() % (max - min + 1);
    } 
}
// thuật toán insert vào mảng để đếm số bước gán.
void insert(int arr[], int* n, int value, int index, int *assignment){
    //đặt lại bộ đếm biến phân công
    *assignment =0;
    // Kiểm tra vị trí cần insert có nằm trong khoảng có thể được insert được không?
    if( index<0 || index > *n)
        return;
    (*n)++;
    // cho chạy vòng lặp từ vị trí đầu mãng tới cuối mãng.
    for (int i = *n -1;i > index; i--)
    {
         (*assignment) ++;
        // di chuyển lần lượt các phần tử i sang vị trí i-1
        arr[i] = arr[i-1];

    }
    // giá trị cho vị trí cần chèn
     (*assignment) ++;
    arr[index] = value; 
}
int main()
{ 
    int n;
    int arr[22];
    int k[5] = {10,20,100,1000,10000};
    int value;
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
            value = min + rand() % (max - min + 1);
            // khởi tạo mảng.
            initializeArray(arr,n,min,max);
            // thực thi hàm insert.
            insert(arr,&n,value,index,&assignment);
            // tính số lần insert trong mỗi vị trí.
            fre[i][index]++;
            // tính trung bình số bước;
            avg[i] = avg[i] + assignment;
        }
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