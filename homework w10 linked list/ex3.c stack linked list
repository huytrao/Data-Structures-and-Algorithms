#include <stdlib.h>
#include <stdio.h>

// Định nghĩa node
typedef struct NodeType {
    int data;
    struct NodeType* next;
} Node;

// Định nghĩa Linked list
typedef struct LinkedListType {
    Node* head;
} LinkedList;

// Khởi tạo linked list
void init(LinkedList* list) {
    list->head = NULL;
}

// Hàm tạo node mới
Node* makeNode(int data) {
    Node* s = (Node*)malloc(sizeof(Node));
    s->data = data;
    s->next = NULL;
    return s;
}

// Hàm chèn node mới vào đầu danh sách
void insertHead(int data, LinkedList* list) {
    Node* newnode = makeNode(data);
    newnode->next = list->head;
    list->head = newnode;
}

// Hàm in linked list
void printList(LinkedList* list) {
    Node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | ", node);
        printf("data = %d | ", node->data);
        printf("next node address = %p\n", node->next);
        node = node->next;
    }
    printf("\n");
}

// Hàm thêm phần tử vào đầu ngăn xếp
void push(LinkedList* stack, int value) {
    insertHead(value, stack);
}

// Hàm lấy phần tử từ đầu ngăn xếp và xóa nó
int pop(LinkedList* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
        return -1; // Giá trị không hợp lệ
    }
    Node* temp = stack->head;
    int data = temp->data;
    stack->head = stack->head->next;
    free(temp);
    return data;
}

// Hàm kiểm tra xem ngăn xếp có rỗng hay không
int isEmpty(LinkedList* stack) {
    return stack->head == NULL;
}

int main() {
    LinkedList stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Phan tu tai dau ngan xep: %d\n", stack.head->data);

    printf("Lay va xoa phan tu: %d\n", pop(&stack));
    printf("Lay va xoa phan tu: %d\n", pop(&stack));

    printf("Phan tu tai dau ngan xep sau khi lay: %d\n", stack.head->data);

    return 0;
}