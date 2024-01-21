#include <stdio.h>

// Xác định u(n)
int u(int n) {
    return n * (n + 1);
}

// Tính tổng S(n) bằng đệ quy
int S(int n) {
    if (n == 1) {
        return u(1);
    } else {
        return S(n - 1) + u(n);
    }
}

// Phân tích hàm S() theo quy trình bốn bước
// 1. Xác định điểm dừng: Khi n = 1
// 2. u(1) =2
// 3. với n =2 u(2) = 2 + 6 =8
// 4. với n =3 u(3) = 2 + 6 + 12 = 18

// Tính tổng S(n) không đệ quy
int S1(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += u(i);
    }
    return sum;
}

int main() {
    int n = 100;

    // Xác định u(n)
    int un = u(n);
    printf("u(%d) = %d\n", n, un);

    // Tính tổng S(n) bằng đệ quy
    int sum = S(n);
    printf("S(%d) = %d\n", n, sum);

    // Phân tích hàm S() theo quy trình bốn bước
    // Câu trả lời có thể được ghi trực tiếp trong chương trình bằng lệnh comment

    // Cài đặt lại hàm S() thành S1() không đệ quy
    int sum1 = S1(n);
    printf("S1(%d) = %d\n", n, sum1);

    return 0;
}