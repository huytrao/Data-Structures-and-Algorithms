#include <stdio.h>
#define MAX 100  // Định nghĩa hằng số MAX là 100

// Định nghĩa cấu trúc dữ liệu Queue (hàng đợi)
typedef struct {
  int head, tail;  // Tiêu đề và đuôi của hàng đợi
  int a[MAX];      // Mảng chứa các phần tử của hàng đợi
} Queue;

// Hàm khởi tạo hàng đợi
void init(Queue* q) {
  q->head = 0;
  q->tail = -1;
}

// Hàm kiểm tra xem hàng đợi có đầy không
int isFull(Queue *q) {
  return (q->tail - q->head == MAX - 1);
}

// Hàm kiểm tra xem hàng đợi có trống không
int isEmpty(Queue *q) {
  return (q->tail < q->head);
}

// Hàm thêm một phần tử vào hàng đợi
void put(Queue* q, int value) {
  q->a[++q->tail] = value;
}

// Hàm lấy một phần tử ra khỏi hàng đợi
int get(Queue* q) {
  int temp = q->a[q->head++];
  return temp;
}

// Hàm hiển thị các phần tử trong hàng đợi
void displayQueue(Queue* q) {
  for(int i = q->head; i <= q->tail; i++) {
    printf("%d ", q->a[i]);
  }
}

// Hàm sắp xếp mảng tăng dần
void sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] > arr[i]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

// Hàm tìm chỉ số của phần tử nhỏ nhất trong mảng
int indx_min(int arr[], int n) {
  int min = 0;
  for(int i = 0; i < n; i++) {
    if(arr[i] < arr[min]) {
      min = i;
    }
  }
  return min;
}

// Hàm tìm chỉ số của phần tử lớn nhất trong mảng
int indx_max(int arr[], int n) {
  int max = 0;
  for(int i = 0; i < n; i++) {
    if(arr[i] > arr[max]) {
      max = i;
    }
  }
  return max;
}

// Hàm tính tổng thời gian nhỏ nhất để xử lý các phần tử trong mảng
int time_smallest(int arr[], int n, int k) {
  Queue q[100];  // Mảng chứa các hàng đợi
  int temp = (int) n/k;  // Số hàng đợi cần thiết

  // Khởi tạo các hàng đợi
  for (int i = 0; i < temp; i++) {
    init(&q[i]);
  }

  // Sắp xếp mảng tăng dần
  sort(arr, n);

  // Thêm các phần tử đầu tiên vào các hàng đợi và tính tổng thời gian
  int sum[100] = {0};  // Mảng lưu tổng thời gian của mỗi hàng đợi
  for(int i = 0; i < temp; i++) {
    put(&q[i], arr[i]);
    sum[i] += arr[i];
  }

  // Thêm các phần tử còn lại vào các hàng đợi theo thứ tự tăng dần của tổng thời gian
  int count = temp;
  while(count < n) {
    put(&q[indx_min(sum, temp)], arr[count]);
    sum[indx_min(sum, temp)] += arr[count];
    count++;
  }

  // Hiển thị các hàng đợi và tổng thời gian của chúng
  printf("\n");
  for(int i = 0; i < temp; i++) {
    displayQueue(&q[i]);
    printf("==>");
        printf("%d",sum[i]);
        printf("\n");
    }
    // trả về giá trị lớn nhất
    return sum[indx_max(sum,temp)];
    
}

int main() {
    int k;
    int n;
    int arr[MAX];
    scanf("%d", &k);
    scanf("%d", &n);
    // nhập vào mảng số nguyên
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // thời gian nhỏ nhất để thực hiện phép tính.
    time_smallest(arr,n,k);

    return 0;
}
