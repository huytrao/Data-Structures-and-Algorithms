#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int arr[], int n, int min, int max) {// ham random tu so be nhat toi so lon nhat
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);// thuat toan random
    } 
}

int binarySearch(int n, int arr[], int value,int*comps) { // ham tim kiem nhi phan
    int end = n - 1;
    int start = 0;
    *comps=0;
    while (start <= end) {  // dieu kien dung vonglap
        *(comps)++;
        int mid = (end + start) / 2; // chia lai 
        if (arr[mid] > value)
        {
            end = mid - 1; // loai bo het tat ca gia tri dang truoc
        }
        else if (arr[mid] < value)
        {
            start = mid + 1; // loai bo het tat ca gia tri nho hon o dang sau
        }
        else if (arr[mid] == value)
        {
            
            return mid;// tra ve vi tri
        }
    }

}

float Average(int arr[], int n, int k, int fre[])// tinh trung binh so buoc
{
    int min = -n*10;
    int max = n*10;
    initializeArray(arr, n, min, max);//khoi tao mang
    float sum = 0;
    for (int i=0; i<k; i++)
    {
        int value = arr[rand() % 20];//phần từ bất kỳ thuộc mảng.
        int comps;
        binarySearch(arr, n, value, &comps);// tim kiem nhi phan
        fre[comps]++;
        sum += comps;// tinh tong
    }
    return sum / k;
}

int main() {
    time_t t;
    srand((unsigned)time(&t));// kahi bao thoi gian
    int arr[20], n = 20;
    int k[5] = {10,20,100,1000,10000};// gan gia tri k
    for (int i=0; i<5;i++)
    {
        printf("k=%d \n", k[i]);
        int fre[21] = {0};// khoi tao bang dem
        float A=Average(arr, n, k[i], fre);
        for (int j = 1; j <= 20; j++)
            printf("%d ", j);
        printf("\n");
        for (int j = 1; j <= 20; j++)
            printf("%d ", fre[j]); // in ra
        printf("\nAverage: %0.3f\n", A);
    }
    return 0;
}