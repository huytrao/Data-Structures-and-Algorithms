#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// hàm sinh mảng ngẫu nhiên float.
void randfloatarr(float arr[], int n, int min, int max) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        float randomFloat = ((float)rand() / RAND_MAX) * (max - min) + min;
        arr[i] = randomFloat;
    }
}
// hàm sắp xếp mảng

void sort(float arr[], int n,int *total) {
     *total =0;
    // chạy vòng lặp
    for (int i = 0; i < n; i++) {
        // gán biến đếm
        int comparisons = 0;
        // đặt giá trị nhỏ nhất.
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            // tăng biến so sanh lên
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                
            }
        }

        // đổi vị trí của biến nhỏ nhất sang vị trí i
        float temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        *total += comparisons; // tính tổng 
    }

}

int main() {
    float arr[10000];
    // thử với n là 40
    int n[6] = {10,20,40,100,500,1000};
    // số lần thử với n
    printf("n=");
    for (int i=0;i<6;i++)
    { 
        printf(" %d",n[i]);
    }
    //in ra total
    printf("\ntotal_comparison=");
    for(int i=0;i<6;i++)
    {
    int total_compare =0;
    // chạy mảng thống kê
    randfloatarr(arr, n, 0, 10);
    sort(arr,n[i],&total_compare);
    printf(" %d",total_compare);
    }
    // kết quả thuật toán
    printf("\n O(n^2)");
    return 0;
}
