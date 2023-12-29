#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Khai báo kiểu dữ liệu Stack
typedef struct Stack_type {
    char a[MAX];  // Mảng lưu trữ các ký tự
    int num[MAX]; // Mảng lưu trữ các số
    int top;      // Chỉ số đỉnh của Stack
} Stack;

// Khởi tạo Stack
void init(Stack *s) {
    s->top = -1;
}

// Kiểm tra Stack có đầy hay không
int isFull(Stack *s) {
    return (s->top == MAX - 1);
}

// Thêm một ký tự vào Stack
void push(Stack *s, char value) {
    if (!isFull(s)) {
        s->a[++(s->top)] = value;
    }
}

// Thêm một số vào Stack
void push_num(Stack *s, int value) {
    if (!isFull(s)) {
        s->num[++(s->top)] = value;
    }
}

// Lấy một số từ Stack
int pop_num(Stack *s) {
    if (s->top >= 0) {
        return s->num[(s->top)--];
    }
    return 0;  // Trả về 0 nếu Stack rỗng
}

// Lấy một ký tự từ Stack
char pop(Stack *s) {
    if (s->top >= 0) {
        return s->a[(s->top)--];
    }
    return '\0';  // Trả về ký tự null nếu Stack rỗng
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
            printf("%c", s->a[i]);
        }
    }
}

// Kiểm tra ký tự có phải là toán tử hay không
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Xác định độ ưu tiên của toán tử
int stt(char a) {
    if (a == '/' || a == '*') {
        // chon mức độ ưu tiên là 2
        return 2;
    }
    if (a == '+' || a == '-') {
        // chọn mức độ ưu tiên là 1
        return 1;
    }
    return -1;
}

// Chuyển biểu thức trung tố thành hậu tố
void Postfix_reverse(char arr[], Stack *s, char temp[]) {
   // đặt giá trị  ind để đếm cho mảng temp tăng lên mỗi khi thêm 1 phần tử vào
    int ind = 0;
    init(s);
    // gán độ dài vòng lặp len
    int len = strlen(arr);
    // thực hiện chạy vòng lặp len 
    for (int i = 0; i < len; i++) {
        char ch = arr[i];
        // nếu nó không phải kí tự đặc biệt thì thêm vào mảng luôn
        if (!isOperator(ch)) {
            temp[ind++] = ch;
        } else {
            // kiểm tra xem nó có lớn hơn hay không
            if (isEmpty(s) || stt(ch) > stt(s->a[s->top])) {
                push(s, ch);
            } else {
                // kiểm tra mức độ uuw tiên cũng của biến hiện tại nếu nó bé hơn thì thực hiện lấy ra cho đến khi nào hết hoặc lớn hơn
                while (!isEmpty(s) && stt(ch) <= stt(s->a[s->top])) {
                    temp[ind++] = pop(s);
                }
                // push trở lại ký tự 
                push(s, ch);
            }
        }
    }
    // hàm lấy lại hết những kết quả khi vòng lặp đã kết thúc nhưng trong stack vẫn còn
    while (!isEmpty(s)) {
        temp[ind++] = pop(s);
    }
    // gián giá trị kết thúc cho mảng
    temp[ind] = '\0';
}

// Tính toán giá trị biểu thức hậu tố
int calculate(char arr[]) {
    Stack s;
    init(&s);
    int n = strlen(arr);
    for (int i = 0; i < n; i++) {
        char ch = arr[i];
        // thực hiện so sánh xem thử có phải số không để cộng vào stack
        if (ch <= '9' && ch >= '0') {
            // chuyển đổi ra số nguyên để thực hiện tính toán
            push_num(&s, ch - '0');
        }
        // kiểm tra xem nó có phải là hàm hoạt động không
        if (isOperator(ch)) {
            // thực hiện việc lấy ra hai số cuối của stack để thực hiện kiểm tra và thực hiện phép tính t
            int num_2 = pop_num(&s);
            int num_1 = pop_num(&s);
            // bảng so sánh đối chiếu
            if (ch == '*') {
                push_num(&s, num_1 * num_2);
            } else if (ch == '/') {
                push_num(&s, num_1 / num_2);
            } else if (ch == '+') {
                push_num(&s, num_1 + num_2);
            } else if (ch == '-') {
                push_num(&s, num_1 - num_2);
            }
        }
    }
    // trả về giá trị kết quả.
    return pop_num(&s);
}

int main() {
    Stack s;
    char temp[MAX];
    char arr[MAX];

    scanf("%s", arr);

    Postfix_reverse(arr, &s, temp);

    printf("%s\n", temp);
    int result = calculate(temp);
    printf("result: %d\n", result);
    return 0;
}
