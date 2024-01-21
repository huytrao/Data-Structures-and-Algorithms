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
        printf("data = %d| ", node->data);
        printf("next node address = %p\n ", node->next);
        node = node->next;
    }
    printf("\n");
}

void insert(LinkedList* list, int data) {
    Node* newNode = makeNode(data);

    // Kiểm tra nếu danh sách liên kết đang rỗng
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    // Kiểm tra nếu node mới có giá trị lớn hơn giá trị node đầu tiên
    Node* temp = list->head;
    if (data >= temp->data) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    Node* current = list->head;

    // Tìm vị trí chèn phù hợp trong danh sách liên kết
    while (current->next != NULL && current->next->data > data) {
        current = current->next;
    }

    // Chèn node mới vào sau current
    newNode->next = current->next;
    current->next = newNode;
}
void delete(LinkedList* list, int value) {
    // Kiểm tra nếu danh sách liên kết đang rỗng
    if (list->head == NULL) {
        return;
    }

    // Nếu node đầu tiên chứa giá trị cần xóa
    if (list->head->data == value) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    Node* current = list->head;
    Node* prev = NULL;

    // Tìm node chứa giá trị cần xóa
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    // Nếu không tìm thấy giá trị trong danh sách
    if (current == NULL) {
        printf("\nNOT FOUND: %d\n", value);
        return;
    }

    // Xóa node chứa giá trị
    prev->next = current->next;
    free(current);
}



int main() {
    LinkedList list;
    Node* q = makeNode(1);
    init(&list);

    // Tạo danh sách tự động
    for (int i = 1; i <=10; i++)
        insert( &list,i);
    insert(&list,200);
    insert(&list,5);
    delete(&list,6);
    delete(&list,211);

    // In danh sách trước khi chèn
    printList(&list);

    return 0;
}