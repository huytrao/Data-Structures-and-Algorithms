#include <stdio.h>
#include <stdlib.h>
void f(int a[], int n,int *comps , int *assgin)
{   // đặt lại giá trị biến gán và biến so sánh
    *assgin =0;
    *comps =0;
    int t;
    // chạy vòng lặp hàm 
    for (int i = 0; i < n - 1; i++)

    {
        (*comps)++;
        // kiểm tra xem chia hết cho 2 không
        if (a[i] % 2 != 0)

        {
            // chạy thêm vòng lặp phụ
            for (int j = i + 1; j < n; j++)

            {
                // so sánh 2 lần
                (*comps)++;
                (*comps)++;
                // so sánh phần tử j trong mảng có chia hết cho 2 không
                // và phần tử đó có nhỏ hơn phận tử ở vị trí j trong mảng không
                if (a[j] % 2 != 0 && a[i] > a[j])

                {
                    // thực hiện phép hoán đổi giá trị nếu thỏa điều kiện 
                    (*assgin)++;
                    t = a[i];
                    (*assgin)++;
                    a[i] = a[j];
                    (*assgin)++;
                    a[j] = t;

                }

            }

        }

    }

}


void main()

{
    // khai báo biến n
    int n = 6;
    // mảng ví dụ 
    int a[] = { 4, 5, 1, 3, 6, 2 };

    // khai báo biến gán và biến gán của số lần so sánh và gán
    int comps=0;
    int assgin=0;
    f(a, n,&comps,&assgin);
    printf("số phép so sánh (comps):%d",comps);
    printf("\n số phép gán (assgin):%d",assgin);

}