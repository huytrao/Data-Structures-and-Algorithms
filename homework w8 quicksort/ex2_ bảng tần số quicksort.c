#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
void Average(int arr[],int n,int k, int fre_left[], int fre_right[],float *sum_left, float *sum_right)
{
    // giá trị nhỏ nhất và giá trị lớn nhất.
    int min = -n*10;
    int max = n*10;
    // khai bao biến 
    int leftshift;
    int rightshift;
    srand(time(0)); // khởi tạo seed cho hầm rand()dựa trên thời gian hiện tại.
    for(int i=0;i<k;i++)
    {
        // biến dời và hàm dời
        // reset lại giá trị biến để chạy vòng mới
        // tạo mảng mới
        initializeArray(arr, n, min, max);
        leftshift =0;
        rightshift = 0;
        quicksort(arr,0,n-1,&leftshift,&rightshift);
        fre_left[leftshift]++;
        fre_right[rightshift]++;
        *sum_left += leftshift;
        *sum_right += rightshift;
    }
    *sum_left /=k;
    *sum_right /=k;
}

void printf_fre_(int n,int k[])
{  
    
    int arr[11];
      for (int i=0; i<4;i++)
    {
        int fre_left[1000] = {0};
        int fre_right[1000] = {0};
        printf("k=%d \n", k[i]);
        float AVG_shift_left =0;
        float AVG_shift_right =0;
        Average(arr, n, k[i],fre_left,fre_right,&AVG_shift_left,&AVG_shift_right);
        printf("pos: ");
        for (int j = 1; j <= n*4; j++)
            printf("%d ", j);
        printf("\n");
        printf("left_shift:");
        for (int j = 1; j <= n*4; j++)
            printf("%d ", fre_left[j]);
        printf("\n");
        printf("right_shift: ");
        for (int j = 1; j <= n*4; j++)
            printf("%d ", fre_right[j]);
        printf("\nAverage left_shift: %0.3f\n",AVG_shift_left );
        printf("\nAverage right_shift: %0.3f\n",AVG_shift_right);
    }

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
    int k[4] = {10, 100, 1000, 10000};
    
    printf_fre_(10,k);

    return 0;
}
