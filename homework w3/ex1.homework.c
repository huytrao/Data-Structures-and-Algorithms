#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Hàm khởi tạo giá trị random cho mảng float
void RanfloatArray(float arr[], int n) {
    for (int i = 0; i < n; ++i) {
        // Sinh số ngẫu nhiên trong khoảng từ -2n đến 2n
        float randomNumber = -2.0 * n + rand() % (4 * n + 1);

        // Làm tròn số randomNumber thành 2 chữ số sau dấu phẩy
        float roundedNumber = ((int)(randomNumber * 100) / 100);

        // Gán số roundedNumber vào mảng arr
        arr[i] = roundedNumber;
    }
}

// hàm tìm giá trị nhỏ nhất
int minIndex(float arr[], int n, int *assign) {
    // đặt biến khởi tạo và biến đếm giá trị nhỏ nhất ban đầu
    // đặt biến số lần gán.
    int index = 0;
    (*assign) = 0;
    float min = arr[0];
    // thực hiện quét giả trị
    for (int i = 1; i < n; i++) {
        // nếu giá trị đang quét nhỏ nhất thì tiến hành gán lại giá trị
        
        if (arr[i] < min) {
            (*assign)++;
            min = arr[i];
            index = i;
        }
    }
    // trả về giá trị
    return index;
}

int main() {
    srand(time(0));
    int n;
    float arr[20];  
    int k[5] = {10, 20, 50, 100, 1000};
    int assignment = 0;
    int fre[5][21] = {0};  // Corrected the array size
    float avg[5] = {0};    // Corrected the array size

    // thực hiện theo các tầng số
    for (int i = 0; i < 5; i++) {
        // chạy các mốc 10 20 100 1000 10000
        for (int j = 0; j < k[i]; j++) {
            // reset lại giá trị n = 20
            n = 20;
            // khởi tạo mảng.
            RanfloatArray(arr, n);

            // thực thi hàm insert.
            int index = minIndex(arr, n, &assignment);
            // tính số lần insert trong mỗi vị trí.
            fre[i][index]++;
            // tính trung bình số bước;
            avg[i] = avg[i] + assignment;
        }
        avg[i] /= k[i];
    }

    for (int i = 0; i < 5; i++) {
        printf("k= %d \n", k[i]);
        for (int j = 0; j <= 20; j++) {
            printf(" %d", j);
        }
        printf("\n");
        for (int j = 0; j < 20; j++) {
            printf(" %d", fre[i][j]);
        }
        printf("\n");
        printf("số bước so sánh: %d \n", n-1);
        printf("số lần gán: %0.3f", avg[i]);
        printf("\n");
    }

    return 0;
}
