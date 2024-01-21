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

// Hàm xóa phần tử đầu danh sách
void deleteHead(LinkedList* list) {
    if (list->head == NULL) {
        return;
    }
    else {
        Node* temp = list->head;
        list->head = temp->next;
        free(temp);
    }
}

// Viết hàm chèn một node vào vị trí thứ k trong danh sách liên kết đơn.
void insert_pos(LinkedList* list, Node* value, int c) {
    int k=c-1;
    int i = 0;
     if (list->head == NULL) {
        value->next = list->head;
        list->head = value;
        return;
    }
    Node* temp1 = list->head;
    Node* temp2 = list->head;
    // tiến hành chạy vòng while 
    // thực hiện trỏ temp1 với while 1 tới vị trí cần chèn.
    while (i < k && temp1 != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
        i++;
    }
    // Kiểm tra i có lớn hơn không?
    if (i < k) {
        return;
    }
    temp2->next = value;
    value->next = temp1;
}
// Hàm xóa một vị trí
void delete_pos(LinkedList* list, int c) {
    int k=c-1;
    int i = 0;
     if (list->head == NULL) {
        printf("NOT FOUND");
        return;
    }
    Node* temp1 = list->head;
    Node* temp2 = NULL;
    // tiến hành chạy vòng while 
    // thực hiện trỏ temp1 với while 1 tới vị trí cần chèn.
    while (i < k && temp1 != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
        i++;
    }
    // Kiểm tra i có lớn hơn không?
    if (i < k) {
        printf("NOT FOUND");
        return;
    }
    if(c==1)
    {
        deleteHead(list);
        return ;
    }
    temp2->next = temp1 ->next;
    free(temp1);
}


int main() {
    LinkedList list;
    Node* q = makeNode(1);
    init(&list);

    // Tạo danh sách tự động
    for (int i = 8; i >=2; i--)
        insertHead(i, &list);

    // In danh sách trước khi chèn
    printf("Before insertion:\n");
    printList(&list);

    // Chèn node q vào vị trí thứ 6 trong danh sách
    delete_pos(&list,2);

    // In danh sách sau khi chèn
    printf("After Delete:\n");
    printList(&list);

    return 0;
}