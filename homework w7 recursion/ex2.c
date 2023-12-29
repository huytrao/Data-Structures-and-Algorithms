#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 20
// khai báo kiểu struct 
typedef struct Stack_type {
    int a[MAX];
    int top;
} Stack;

// khai báo kiểu quêt
typedef struct {
    int head, tail;
    int a[MAX];
} Queue;

// khàm khởi tạo sd
void init(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return (s->top == MAX - 1);
}

// hàm push một giá trị vào stack
void push(Stack *s, int value) {
    s->top++;
    s->a[s->top] = value;
}

// hàm pop một giá trị ra khỏi stack
int pop(Stack *s) {
    return s->a[s->top--];
}
// hàm kiểm tra có phải emply hay không
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// hàm in stack
void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("NULL");
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->a[i]);
        }
    }
    printf("\n");
}
// hàm pop tất cả giá trị ra khỏi recur
void pop_all_recur(Stack *s) {
    if (s->top == -1) {
        return;
    }
    pop(s);
    pop_all_recur(s);
}
// hàm khởi tạo q
void init_q(Queue *q) {
    q->head = 0;
    q->tail = -1;
}
// hàm kiểm tra quêu có đầy chưa
int isFull_q(Queue *q) {
    if(q->tail - q->head == MAX - 1)
        return 0;
    return 1;
}
// hàm kiểm tra xem có rỗng hay không
int isEmpty_q(Queue *q) {
    return (q->tail < q->head);
}
// hàm đặt q vào value
void put(Queue *q, int value) {
    q->a[++q->tail] = value;
}
// hàm get giá trị q vào head
int get(Queue *q) {
    int temp = q->a[q->head];
    q->head++;
    return temp;
}
// hàm hiển thị Quêu
void displayQueue(Queue *q) {
    if(!isEmpty_q(q))
    {
    for (int i = q->head; i <= q->tail; i++) {
        printf("%d ", q->a[i]);
    }
    printf("\n");
    }
    else
        printf("NULL");
}
// hàm thực hiện lấy đệ quy 
void get_recur(Queue *q) {
    if (q->head <= q->tail) {
        get(q);
        get_recur(q);
    }
}
// hàm main
int main() {
    // khai báo các biến 
    Stack s;
    Queue q;
    init(&s);
    init_q(&q);
    // thực hiện push vào stack các giá trị
    printf("\nStack: ");
    for (int i = 0; i < 20; i++) {
        push(&s, i);
    }
    displayStack(&s);
    pop_all_recur(&s);
    displayStack(&s);

    printf("\nQueue: ");
    for (int i = 0; i < 20; i++) {
        put(&q, i);
    }
    // đưa ra stack các giá trị
    displayQueue(&q);
    get_recur(&q);
    displayQueue(&q);

    return 0;
}

