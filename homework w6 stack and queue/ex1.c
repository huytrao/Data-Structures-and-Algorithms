#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// khai báo max bằng 1000
#define MAX 1000
// khai báo kiểu struct cho stack
typedef struct Stack_type{
    char a[MAX];
    int top;
} Stack;
// gán giá trị ban đầu cho stack
void init(Stack *s){
    // gán vị trí cuối là bằng 1;
    s->top = -1;
}
// kiểm tra xem Stack có đầy hay không 
int isFull(Stack *s)
{
    if(s->top == MAX -1)
    {
        return 1;
    }
    return 0;
}
// hàm push để thêm phần tử vào cuối 
void push(Stack *s, char value)
{
    s->top ++;
    s->a[s->top] = value;
}
//hàm pop để lấy giá trị ở phần tử ở vị trí top ra
char pop(Stack *s)
{
    return s->a[s->top --];
}
int isEmpty(Stack *s)
{
    if(s->top <=0)
        return 1;
    return 0;
}
// hàm hiển thị stack
void displayStack(Stack *s)
{   // kiểm tra stack có tồn tại hay không
    if(isEmpty(s))
    {
        printf("NULL");
    }
    else{
        for(int i=0;i<s->top;i++)
        {
            printf("%c",s->a[i]);
        }
    }
}
// hàm swap 2 ký tự 
void swap(char *a, char *b)
{
    // thực hiện thuật toán thay đổi
    char c=*b;
    *b = *a;
    *a=c;
}
// hàm reverse chuỗi thường
void reverses_normal(char arr[])
{
    // lưu giá trị biến strlne
    int n= strlen(arr);
    for(int i=0;i<((n+1)/2);i++)
    {
        // chuyển đổi vị trí 2 thuật toán
        swap(&arr[i],&arr[n-i-1]);
    }
}
// hàm rverse chuổi sử dụng stack
void reverses_stack(char arr[], Stack *s)
{   int n= strlen(arr);
    for(int i=0;i<n ;i ++)
    {
        // lấy từng giá trị vào stack 
        push(s, arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        // lấy giá trị cuối và gán vào giá trị đầu của mảng
        arr[i]= pop(s);
    }
}

// hàm in mảng
void print_arr(char arr[])
{
    // chạy vòng lặp và thực hiện in mảng
    for(int i=0;i<strlen(arr);i++)
    {
        printf("%c",arr[i]);
    }
}

int main()
{   Stack s;
    init(&s);
    // khởi tạo mảng 
    char arr_1[MAX];
    char arr_2[MAX];
    scanf("%s",arr_1);
    for(int i=0;i<strlen(arr_1);i++)
    {
        arr_2[i] = arr_1[i];
    }
    arr_2[strlen(arr_1)]='\0';
    // hàm sử dụng normarl stack
    reverses_normal(arr_1);
    printf("reverses normal :  ");
    print_arr(arr_1);
    printf("\n");
    // hàm sử dụng reverses stack
    reverses_stack(arr_2,&s);
    printf("reverses stack :  ");
    print_arr(arr_2);
    printf("\n");
}