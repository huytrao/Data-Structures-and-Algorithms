#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// hàm f(x) = a - 2b + 3c
float f(float a[])
{
    int result = a[0] - 2*a[1] + 3*a[2];
    return result;
}
void initializearr(float arr[][3], int n) {
  // tạo hạt giống
  srand(time(NULL));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      // gán giá trị vào
      arr[i][j] = -100.0 + ((float)rand() / RAND_MAX) * (200.0);
    }
  }
}
// hàm sắp xếp
void bubbleSort(float arr[][3], int n) {
    float temp[3];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // so sánh điều kiện
            if (f(arr[j]) < f(arr[i])) {
                // đổi vị trí nếu sai
                for(int k=0;i<3;i++)
                {
                temp[k] = arr[j][k];
                arr[j][k] = arr[i][k];
                arr[i][k] = temp[k];
                }
            }
        }
    }
}
int main()
{
    int n=10;
    // nập số lượng phần tử
    float arr[100][3];
    // random chuỗi ký tự
    initializearr(arr,n);
    // sắp xếp chuoi

    // bubbleSort(arr,n);
    printf("\n");
    // in kết quả
        for(int i=0;i<n;i++)
    {
        // ỉn a kết quả sau khi sắp xếp
        printf(" (%0.3f,%0.3f,%0.3f)",arr[i][0],arr[i][1],arr[i][2]);
    }
    
}