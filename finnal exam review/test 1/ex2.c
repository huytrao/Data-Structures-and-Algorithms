#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Định nghĩa node
typedef struct NodeType {
    char data;
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
Node* makeNode(char data) {
    Node* s = (Node*)malloc(sizeof(Node));
    s->data = data;
    s->next = NULL;
    return s;
}

// Hàm chèn node mới vào cuối danh sách
void insertEnd(char data, LinkedList* list) {
    Node* newnode = makeNode(data);

    // Nếu danh sách rỗng, thêm node vào đầu danh sách
    if (list->head == NULL) {
        list->head = newnode;
        return;
    }

    // Duyệt đến cuối danh sách
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Chèn node vào cuối danh sách
    current->next = newnode;
}

// Hàm in linked list
void printList(LinkedList* list) {
    Node* node = list->head;
    while (node != NULL) {
        printf("%c", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    char str[] = "DSATTHS12023";
    int length = strlen(str);

    init(&list);

    // Chèn từng ký tự của chuỗi vào danh sách
    for (int i = 0; i < length; i++)
        insertEnd(str[i], &list);

    // In chuỗi từ danh sách
    printf("Chuoi: ");
    printList(&list);

    return 0;
}