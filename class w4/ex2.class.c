#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// hàm tạo mảng số thực
void initializeArray(float arr[], int n, int min, int max) {
    int i;
    srand(time(0));
    for (i = 0; i < n; i++) {
        // gán giá trị cho mỗi số thực sinh ra được
        arr[i] = min + rand()/RAND_MAX*(max - min + 1);
    }
}
// hàm sắp xếp
void bubbleSort(float array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            
            if (array[j] < array[i]) {
                
                int temp;
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}
int main()
{
    int n;
    // nập số lượng phần tử
    scanf("%d",&n);
    float arr[100];
    // nhập mảng
    for(int i=0;i<n;i++)
    {
        scanf("%f",&arr[i]);
    }
    // sắp xếp mảng
    bubbleSort(arr,n);
    printf("\n");
    // in kết quả
    for(int i=0;i<n;i++)
    {
        printf(" %0.3f",arr[i]);
    }
}