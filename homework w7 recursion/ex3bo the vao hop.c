#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack
{
    int a[20];
    int top;
} Stack;

void init(Stack* s)
{
    // Gán giá trị trên cùng là -1
    s->top = -1;
}

int isEmpty(Stack* s)
{
    return (s->top == -1);
}

void push(Stack* s, int value)
{
    s->top++;
    s->a[s->top] = value;
}

int pop(Stack* s)
{
    if(isEmpty(s))
        return 0;
    return s->a[s->top--];
}

int Sinhmang(int arr[], int n)
{
    int check = 0;
    srand(time(NULL)); // Sửa lỗi ở đây, thêm thời gian bây giờ
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = 1 + rand() % (10 - 1 + 1);
        if (arr[i] == 1)
            check = 1;
    }
    // đảm bảo luôn có số 1 trong mảng
    if (check != 1)
    {
        arr[0] = 1;
    }
}

// hàm bỏ theo vào hợp sài recur
int bothevaohop_recur(Stack* s, int arr[], int n)
{
    // kiểm tra trong hàm có phải 1 không nếu có thì dừng lại
    if (s->a[n - 1] == 1)
    {
        return 0;
    }
    // thực hiện thêm thẻ vào hộp
    push(s, arr[n - 1]);
    bothevaohop_recur(s, arr, n - 1);
}

int SUM_The_recur(Stack* s)
{
    // Kiểm tra xem ngăn xếp có trống không
    if (isEmpty(s))
    {
        return 0; // Trường hợp cơ sở: nếu ngăn xếp trống, trả về 0
    }
    
    // Lấy giá trị từ ngăn xếp và cộng vào tổng với giá trị của các phần tử còn lại
    return pop(s) + SUM_The_recur(s);
}

int main()
{
    Stack s;
    init(&s);

    int arr[20];
    Sinhmang(arr, 20);

    printf("Mang duoc tao: ");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bothevaohop_recur(&s, arr, 20);

    printf("Tong cua cac phan tu trong stack: %d\n", SUM_The_recur(&s));

    return 0;
}
