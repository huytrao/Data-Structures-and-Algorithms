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
// hàm chuyển đổi {->} [->] (->)
char convert_braces_brackets(char key)
{
    if(key == '{')
    {
        return '}';
    }
    if(key == '[')
    {
        return ']';
    }
    if(key == '(')
    {
        return ')';
    }
}
// hàm phát hiện lỗi dấu ngoặc và sửa lại sao cho đúng
void fix_braces_brackets(char arr[])
{   // khai báo biến kiểm tra nó có bị lỗi dấu hay không
    int check = 1;
    // khai báo stack
    Stack s;
    // khởi tạo stack
    init(&s);
    // khai báo biến lỗi để lưu vị trí lỗi
    int error[20];
    int err_num =0;
    int n = strlen(arr);
    for(int i=0;i<n;i++)
    {
        // thực hiện kiểm tra tại vị trí i có phải dấu ngoặc để thực hiện thêm vào stack
        if( arr[i]=='{' || arr[i]=='[' || arr[i] == '(')
        {
                push(&s,arr[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        // kiểm  tra xem với ngoặc dóng tương ứng có đúng hay không
        if(arr[i]=='}' || arr[i]==']' || arr[i] == ')' )
        {
            char temp = pop(&s);
            // nếu khác thì thực hiện lưu vị trí lỗi và chèn ngoặc đúng vào mảng.
            if(arr[i] != convert_braces_brackets(temp)){
                check =0;
                error[err_num]=i;
                err_num++;
                arr[i] = convert_braces_brackets(temp);
            }
        }
    }
    // kiểm tra xem mảng có bị lỗi dấu hay không nếu lỗi thì thực hiện in ra
    if(check == 0){
        printf("Error at: ");
        for(int i=0;i<err_num;i++)
        {
            printf("%d ",error[i]+1);
        }
        printf("\n");
        for(int i=0;i<n;i++)
        {
            printf("%c",arr[i]);
        }
        printf("\n");
    }
    else{
        printf("No error");
    }
}
int main()
{
    char arr[100];
    scanf("%s",arr);
    // thực hiện fix mảng
    fix_braces_brackets(arr);
}