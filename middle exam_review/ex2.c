#include <stdio.h>
// hàm kiểm tra có phải số chẳn hay không nếu có trả về nếu
int even(int a)
{
    if (a % 2 != 0)
        return 1;
    return 0;
}
// hàm sinh mảng
void initializeArray(int arr[], int n, int min, int max)
{
    int i;
    srand(time(0)); // khởi tạo seed cho hầm rand()dựa trên thời gian hiện tại.
    for (i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
        // Sinh ngẫu nhiên giá trị trong khoảng [min,max]
    }
}
// hàm swap
void swaps(int *a, int *b)
{
    *a = *b + *a;
    *b = *a - *b;
    *a = *a - *b;
}
// hàm odđ Even kiểm tra
void oddEven(int a[], int n, int *swap, int *comps)
{
    *swap = 0;
    *comps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // đặt min max
        int min_even = 0;
        int max_not_even = 0;
        (*comps)++;
        if (even(a[i]))
        {
            min_even = i;
        }
        else
            max_not_even = n - i - 1;
        // chạy các phần tử ở bên trong
        for (int j = i + 1; i < n; j++)
        {
            (*comps)++;
            if (even(a[j]))
            {
                (*comps)++;
                if (a[j] < a[min_even])
                    min_even = j;
            }
            else
                (*comps)++;
            if (a[max_not_even] < a[n - j - 1])
                max_not_even = j;
        }
        // thực hiện so sánh và chuyển đổi
        (*comps)++;
        if (even(a[i]))
        {
            *swap++;
            swaps(&a[min_even], &a[i]);
        }
        else
            *swap++;
        swaps(&a[max_not_even], &a[i]);
    }
}
float Average(int arr[], int n, int k, int fre_swap[],int fre_comps[],float *sum_swap, float *sum_comp)
{
    int min = -n * 10;
    int max = n * 10;
    initializeArray(arr, n, min, max);
    float sum = 0;
    for (int i = 0; i < k; i++)
    {
        int value = arr[rand() % 20]; // phần từ bất kỳ thuộc mảng.
        int comps;
        int swap;
        oddEven(arr, n, &swap, &comps);
        fre_comps[comps]++;
        fre_swap[comps]++;
        *sum_comp += comps;
        *sum_swap += swap;
    }
    *sum_swap / k;
    *sum_comp /k;
}

int main()
{   
     int fre_swap[100];int fre_comps[100];float sum_swap; float sum_comp;
    int arr[100];
    int n = 10;
    initializeArray(arr, n, n * -20, n * 20);
    oddEven(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    Average(arr,n,10000,fre_comps,fre_swap,&sum_swap,&sum_comp);

}