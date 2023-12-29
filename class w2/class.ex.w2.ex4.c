#include <stdio.h>

int binarySearch(int n, int arr[], int value) { // ham tim kiem nhi phan
    int end = n - 1;
    int start = 0;
    int dem = 0;

    while (start <= end) {  // dieu kien dung vonglap
        dem++;
        int mid = (end + start) / 2; // Fixing mid-point calculation

        if (arr[mid] > value)
            end = mid - 1; // loai bo het tat ca gia tri dang truoc
        else if (arr[mid] < value)
            start = mid + 1; // loai bo het tat ca gia tri nho hon o dang sau
        else if (arr[mid] == value)
            return dem;
    }

    return dem; // Return -1 if value is not found
}

int linearSearch(int n, int arr[], int value) { // ham tim kiem
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i + 1; // tra ve so buoc
        }
    }

    return n; // tra ve so luong bang voi n neu khong tim thay
}
int main() {
    int arr[1000];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int value;
    scanf("%d", &value);

    printf("\n steplinear : %d", linearSearch(n, arr, value)); // in ra ket qua
    printf("\n stepbinary : %d", binarySearch(n, arr, value)); // in ra ket qua

    return 0;
}
