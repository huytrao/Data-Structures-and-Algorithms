#include <stdio.h>
// thuật toán xắp xếp buble sort
void f(int a[], int n, int *compars, int *swaps)
{
    // đặt lại giá trị của biến đếm về 0
    *compars = 0;
    *swaps = 0;
    // chạy từ 0 đến nờ trừ 1
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            // tăng số phép so sánh lên vì đây là phép so sánh phần tử j-1 và phần tử j
            (*compars)++;

            if (a[j - 1] > a[j])
            {
                // tự hiện đổi hai biến 
                int tem = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tem;
                (*swaps)++;
            }
        }
    }
}

int main()
{   // khai báo biến
    int compars = 0;
    int swaps = 0;
    int a[8] = {9, 14, 8, 7, 10, 9, 4};
    // có bao nhiêu
    int n = 7;

    f(a, n, &compars, &swaps);
    // in kết quả 
    printf("Mảng sau khi sắp xếp: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nSố phép so sánh: %d\n", compars);
    printf("Số phép hoán vị: %d\n", swaps);

}
