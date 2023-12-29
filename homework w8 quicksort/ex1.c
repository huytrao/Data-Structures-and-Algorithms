#include <stdio.h>
#include <stdlib.h>

// Hàm hoán đổi giữa hai phần tử
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// hàm sinh mảng.
void initializeArray(int arr[], int n, int min, int max)
{
    // đặt giá trị i ban đầu.
    int i;
    srand(time(0)); // khởi tạo seed cho hầm rand()dựa trên thời gian hiện tại.
    for (i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
        // Sinh ngẫu nhiên giá trị trong khoảng [min,max]
    }
}


// Hàm phân hoạch
int partition(int arr[], int left, int right,int *shiftleft,int *shiftright)
    {// đặt pivot ở trên trái
    int pivot = right;
    // giảm right xuống để tiến hành so sánh
    right--;

    while (1) {
        // tiến hành chạy vòng while đến khi nào tìm được giá trị lớn hơn pivot thì dừng
        while (arr[left] <= arr[pivot] && left < pivot) {
            // tăng biến dời lên
            (*shiftleft)++;
            left++;
        }
        // chạy đến khi nào tìm được vị trí có giá trị bé hơn vị trí pivot thì dừng
        while (arr[right] >= arr[pivot] && right > left) {
            // tăng biến dời lên
            (*shiftright)++;
            right--;
        }

        if (left >= right) {
            // nếu left lớn hơn right thì tiến hành break vòng lặp
            break;
        } else {
            // còn ngược lại thì tiến hành hoán đổi giá trị của right và left
            swap(&arr[left], &arr[right]);
        }
    }
    // đổi vị trí left với giá trị nhỏ nhất 
    swap(&arr[left], &arr[pivot]); 
    //  trả về vị trí sau khi đã chia 
    return left;
}

// Hàm quicksort
void quicksort(int arr[], int left, int right,int *shiftleft,int *shiftright) {
    if (left < right) {
        
        // Phân hoạch mảng và nhận vị trí của pivot
        int pivotIndex = partition(arr, left, right,shiftleft,shiftright);

        // Gọi đệ quy cho hai phần của mảng
        quicksort(arr, left, pivotIndex - 1,shiftleft,shiftright);
        quicksort(arr, pivotIndex + 1, right,shiftleft,shiftright);
    }
}
float Average(int arr[],int n,int k, int fre_left[], int fre_right[],float *sum_left, float *sum_right)
{
    // giá trị nhỏ nhất và giá trị lớn nhất.
    int min = -n*10;
    int max = n*10;
    initializeArray(arr, n, min, max);
    float sum =0;
    for(int i=0;i<k;i++)
    {
        // biến dời và hàm dời
        int leftshift;
        int rightshift;
        quicksort(arr,0,n-1,&leftshift,&rightshift);
        // tăng số lần dời lên
        fre_left[leftshift]++;
        fre_right[rightshift]++;
        *sum_left += leftshift;
        *sum_right += rightshift;
    }
    *sum_left /k;
    *sum_right /k;
}

// Hàm in mảng
void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm nhập mảng
void input_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}


int main() {
    int n;
    int arr[100];
    scanf("%d", &n);

    input_arr(arr, n);
    // đặt giá trị ban đầu cho biến dời 
    int leftshift=0,rightshift =0;
    // hàm sắp xếp nhanh.
    quicksort(arr, 0, n - 1,&leftshift,&rightshift);

    print_arr(arr, n);
    printf("\n leftshift:%d",leftshift);
    printf("\n rightshift:%d\n",rightshift);
    
    return 0;
}
