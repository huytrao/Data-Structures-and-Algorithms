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

// Hàm kiểm tra xem hàng đợi có rỗng hay không
int isEmpty(LinkedList* queue) {
    return queue->head == NULL;
}

// Hàm lấy phần tử đầu hàng đợi và xóa nó
int get(LinkedList* queue) {
    if (isEmpty(queue)) {
        printf("Khong lay duoc phan tu, hang doi rong.\n");
        return -1; // Giá trị đặc biệt để chỉ không có phần tử
    }

    Node* temp = queue->head;
    int value = temp->data;
    queue->head = temp->next;
    free(temp);

    return value;
}

// Hàm đặt phần tử vào cuối hàng đợi
void put(int data, LinkedList* queue) {
    Node* newnode = makeNode(data);

    // Trường hợp danh sách rỗng
    if (queue->head == NULL) {
        queue->head = newnode;
        return;
    }

    // Tìm đến cuối danh sách
    Node* current = queue->head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Chèn vào cuối danh sách
    current->next = newnode;
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

int main() {
    LinkedList queue;
    init(&queue);

    put(10, &queue);
    put(20, &queue);
    put(30, &queue);
     printList(&queue);
    printf("Phan tu tai dau hang doi: %d\n", queue.head->data);
    
    printf("Lay va xoa phan tu: %d\n", get(&queue));
    printList(&queue);
    printf("Lay va xoa phan tu: %d\n", get(&queue));
    printList(&queue);

    if (!isEmpty(&queue)) {
        printf("Phan tu tai dau hang doi sau khi lay: %d\n", queue.head->data);
    } else {
        printf("Hang doi rong.\n");
    }

    return 0;
}