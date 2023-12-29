#include <stdio.h>

// Hàm tìm kiếm nhị phân đệ quy
int binarySearch_recur(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;
    // đặt mid
    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    // thực hiện đệ quy
    if (arr[mid] < target)
        return binarySearch_recur(arr, mid + 1, high, target);
    else
        return binarySearch_recur(arr, low, mid - 1, target);
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int target = 7;

    // Gọi hàm tìm kiếm nhị phân đệ quy
    int result = binarySearch_recur(arr, 0, n - 1, target);

    if (result == -1)
        printf("Không tìm thấy %d trong mảng.\n", target);
    else
        printf("%d được tìm thấy tại vị trí %d trong mảng.\n", target, result);

    return 0;
}
