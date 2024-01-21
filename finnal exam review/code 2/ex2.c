#include <stdlib.h>
#include <stdio.h>
// Nhận định trong danh sách liên kết đơn thì khá phù hợp với 
// Định nghĩa node

// hao tác truy cập nhanh đến phần tử trong Stack vì chỉ cần sử dụng chỉ số của mảng.
// Không cần sử dụng bộ nhớ động và không cần quản lý việc cấp phát hay giải phóng bộ nhớ.
// Nhược điểm:
// Kích thước mảng phải được xác định trước và không thay đổi được trong quá trình thực thi. Điều này có thể gây hạn chế về tổng số phần tử trong Stack.
// Khi Stack đạt đến giới hạn kích thước, việc thêm phần tử mới sẽ không thể thực hiện và gây ra lỗi tràn mảng (overflow).
// Danh sách liên kết đơn:
// Ưu điểm:
// Khả năng mở rộng kích thước của Stack một cách linh hoạt trong quá trình thực thi. Việc thêm hoặc xóa phần tử mới chỉ cần thay đổi liên kết giữa các nút.
// Không gây hạn chế về tổng số phần tử trong Stack do có thể sử dụng bộ nhớ động để cấp phát nút mới.
// Nhược điểm:
// Truy cập đến phần tử trong Stack sẽ phải thông qua việc duyệt qua các nút trong danh sách, do đó truy cập chậm hơn so với mảng.
// Đòi hỏi quản lý bộ nhớ động, bao gồm việc cấp phát và giải phóng bộ nhớ, có thể gây ra lỗi memory leak nếu không được quản lý cẩn thận.

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