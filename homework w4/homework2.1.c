#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void initializeArr(int arr[], int n) {
  // tạo hạt giống
  srand(time(NULL));

  for (int i = 0; i < n; i++) {
      // gán giá trị vào
      arr[i] =-100 + rand()%(201);
  }
}
// hàm xóa các phần tử vừa tìm được bằng linear search
void delete(int arr[],int *n,int index,int *step)
{   // di chuyển các phàn tử i+1 sang i
    for(int i=index;i<*n;i++)
    {   (*step)++;
        (*step) ++;
        arr[i]=arr[i+1];
    }
    (*step)++;
    // giảm mảng
    (*n)--;
}

void deleteLinear(int arr[],int *n,int *step1)
{   (*step1)=0;
// thuật toán sánh toàn bộ mảng
    for(int i=0;i<*n-1;i++)
    {   (*step1)++;
        for(int j=i+1;j<*n;j++)
        {   (*step1)++;
            (*step1) ++;
            // nếu tìm thấy 2 phần tử giống nhau thì xóa
            if(arr[i]==arr[j])
            {   // xóa phần tử
                delete(arr,n,j,step1);
                (*step1)++;
                j--;// lùi lại j để quét được phần tử kế tiếp
            }
        }
    }
    
}
void deleteSort(int arr[],int *n,int *step2)
{
    (*step2) =0;
    int temp;
    // hàm buble sort
    for(int i=0;i<*n-1;i++)
    {   (*step2) ++;
        for(int j=i+1;i<*n;i++)
        {
            (*step2) ++;
            (*step2) ++;
            if(arr[j]<arr[i])
            {
                (*step2) ++;
                temp = arr[i];
                (*step2) ++;
                arr[i]=arr[j];
                (*step2) ++;
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<*n;i++)
    {
        (*step2) ++;
        if(arr[i]==arr[i+1])
        {
            // xóa phần tử ở vị trí i+1 nếu nó trùng
            delete(arr,n,i+1,step2);
            (*step2) ++;
            i--;
        }
    }

}

int main() {
    int arr[1000];
    int irr = 10;
    int step1 = 0;
    int step2 = 0;
    int n[6] = {10, 20, 50, 100, 500, 1000};
    int k[6] = {10, 100, 200,500,1000, 2000};

    for (int i = 0; i < 6; i++) {
        // in k
        printf("\n k=%d\n", k[i]);
        printf("n= ");

        // in n
        for (int i1 = 0; i1 < 6; i1++) {
            printf(" %d", n[i1]);
        }
        // xóa phần tử linear step
        printf("\n dellinearsteps= ");

        for (int i2 = 0; i2 < 6; i2++) {
            // đặt biến tạm để chứa giá trị trung bình
            float avg = 0;

            for (int i3 = 0; i3 < k[i]; i3++) {
                    int temp = n[i2];
                    // tạo mảng
                    initializeArr(arr, n);
                    step1 = 0;
                    // hàm  tính step
                    deleteLinear(arr, &n[i2], &step1);
                    avg += step1;
                    n[i2] = temp;
            }
        // tính giá trị trung bình của mỗi n;
            avg = avg / k[i];
            // in ra kết quả
            printf(" %0.3f", avg);
        }

        printf("\n delsortsteps= ");

        for (int i2 = 0; i2 < 6; i2++) {
            float avg = 0;
            // thực hiện chạy k[i]lần
            for (int i3 = 0; i3 < k[i]; i3++) {
                    int temp = n[i2];
                    // sinh mảng
                    initializeArr(arr, i);
                    step2 = 0;
                    // sử dụng hàm delesort để tính step.
                    deleteSort(arr, &n[i2], &step2);
                    avg += step2; // cộng tổng các step trong k[i] lần
                    n[i2] = temp;
            }
            // tính trung bình
            avg = avg / k[i];
            // in ra kết quả
            printf(" %0.3f", avg);
        }
    }

    return 0;
}