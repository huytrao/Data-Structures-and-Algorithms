#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randarr(int arr[], int n, int min, int max) {
  srand(time(NULL));

  for (int i = 0; i < n; i++) {
    //gán giá trị random vào từng phần tử.
    arr[i] = min + rand() % (max - min + 1);
  }
}
// Hàm xóa phần tử ở vị trí i
void delete(int arr[], int *n, int index) {
 
}

void bubbleSort(int arr[], int n) {
  int swaps;

  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      // kiểm tra giá trị có lớn hơn không nếu ở j-1 lớn hơn j thì đổi giá trị.
      if (arr[j - 1] > arr[j]) {
        swaps = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = swaps;
      }
    }
  }
}
// Trường hợp A 
void CaseA(int arr[], int *n, int year) {
  for (int i = 0; i < *n; i++) {
    if (arr[i] >= year) {
      for (int j = i; j < *n - 1; j++) {
        // dịch chuyển vị trí từ vị trí j+1 sang j
        arr[j] = arr[j + 1];
      }
      (*n)--;
      i--;
    }
  }
}

//Trường hợp B
int CaseB(int arr[], int *n, int year) {
    // sắp xếp lại mảng từ bé đến lớn
  bubbleSort(arr, *n);

  for (int i = 0; i < *n; i++) {
    if (arr[i] >= year) {
      *n = i; // bỏ luôn giá trị phía sau.
      return;
    }
  }
}//Hàm xuất mảng
void printarr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int arr[101];
  int n = 100;
  int year;

  scanf("%d", &year);

  randarr(arr, n, 1998, 2023);
    // thử trường hợp 1
  CaseA(arr, &n, year);
  printarr(arr, n);
  printf("\n========================\n");
    // thử trường hợp 2
     n = 100;

  randarr(arr, n, 1998, 2023);
 
  CaseB(arr, &n, year);
  printarr(arr, n);

  return 0;
}