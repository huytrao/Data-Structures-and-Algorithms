#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

// Khai báo cấu trúc dữ liệu client
// Thêm vào cấu trúc town_WIFI và Client
struct town_WIFI
{
    int route_position;
    int floor;
};

struct Client
{
    int right_function;
    int ID;
};

// Thay đổi kiểu của Stack
typedef struct Stack_type {
    struct town_WIFI a[MAX];
    struct Client num[MAX];
    int top;
} Stack;
// kiểm tra xem stack full hay không
int isFull(Stack *s) {
    return (s->top == MAX - 1);
}
// Sửa hàm push và push_num
void push(Stack *s, struct town_WIFI value) {
    if (!isFull(s)) {
        s->a[++(s->top)] = value;
    }
}

void push_num(Stack *s, struct Client value) {
    if (!isFull(s)) {
        s->num[++(s->top)] = value;
    }
}

// Lấy một số từ Stack
struct Client pop_num(Stack *s) {
    if (s->top >= 0) {
        return s->num[(s->top)--];
    }
    struct Client empty_client = {0, 0}; // Return an empty client if the stack is empty
    return empty_client;
}


// Kiểm tra Stack có trống hay không
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// Hiển thị nội dung của Stack
void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("NULL");
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf("\nM_%d", s->a[i].route_position);
            printf("\nfloor:%d", s->a[i].floor);
            printf("\nclient:%d", s->num[i].ID);
            printf("\nright_function:%d", s->num[i].right_function);
        }
    }
}


// Hàm kiểm tra chức năng của thiết bị di động
int check_function(int function) {
    // Nếu chức năng của thiết bị di động là 1, cho phép truy cập internet
    if (function == 1) {
        return 1;
    }
    // Ngược lại, chặn truy cập internet
    return 0;
}

// Hàm kiểm soát truy cập internet của thiết bị di động
void control_access(Stack *s, struct Client c) {
    // Lấy điểm truy cập WIFI hiện tại ra khỏi Stack
     struct town_WIFI current_wifi = pop_num(s);

    // Kiểm tra chức năng của thiết bị di động
    int is_allowed = check_function(c.right_function);

    // Nếu thiết bị di động được phép truy cập internet, in thông báo
    if (is_allowed) {
        printf("Thiết bị di động có ID = %d được phép truy cập internet tại điểm truy cập WIFI M_%d, tầng %d.\n", c.ID, m_i, s->a[m_i].floor);
    }
    // Ngược lại, in thông báo
    else {
        printf("Thiết bị di động có ID = %d bị chặn truy cập internet tại điểm truy cập WIFI M_%d, tầng %d.\n", c.ID, m_i, s->a[m_i].floor);
    }
}

int main() {
    // Khai báo các biến
    Stack s;
    struct town_WIFI t1, t2;
    struct Client c1;

    // Khởi tạo cấu trúc dữ liệu
    init(&s);

    // Thêm điểm truy cập WIFI vào Stack
    t1.route_position = 1;
    t1.floor = 1;
    push(&s, t1);

    // Thêm thiết bị di động vào Stack
    c1.right_function = 1;
    c1.ID = 1;
    push_num(&s, c1);

    // Kiểm soát truy cập internet của thiết bị di động
    control_access(&s, c1);

    // Lấy điểm truy cập WIFI ra khỏi Stack
    pop(&s);

    // Thêm thiết bị di động vào Stack
    c1.right_function = 2;
    c1.ID = 2;
    push_num(&s, c1);

    // Kiểm soát truy cập internet của thiết bị di động
    control_access(&s, c1);

    // Kết thúc chương trình
    return 0;
}
