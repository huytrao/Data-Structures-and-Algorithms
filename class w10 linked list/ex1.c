#include <stdio.h>
#include <stdlib.h>

//Định nghĩa node
typedef struct NodeType {
    int data;
    struct NodeType* next;
}Node;

//Định nghĩa Linked list
typedef struct LinkedListType{
    Node* head;
}LinkedList;

//Khởi tạo linked list
void init(LinkedList* list) {
    list->head = NULL;
}

//Hàm tạo node mới
Node* makeNode(int data){
    Node *s =  (Node*)malloc(sizeof(Node));
    // ham data 
    s->data = data;
    s->next = NULL;
    return s;
}

//Hàm chèn node mới vào đầu danh sách
// lish
void insertTail(int data, LinkedList* list) {
    Node *p = makeNode(data);
    if(list->head == NULL)
    {
        list->head =p;
    }
    else
    {
        Node *tmp = list->head;
        while ( tmp->next!= NULL)
        {
            tmp = tmp ->next;
        }
        // chèn vào cuối
        tmp ->next = p;
    }
   
}

void insertHead(int data, LinkedList* list){
    Node *newnode = makeNode(data);
    newnode ->next = list->head;
    list->head = newnode;
}
//Hàm in linked list
void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | ", &(node->data));
        printf("data = %d| ", node->data);
        printf("next node address = %p\n ", node->next);
        node = node->next;
    }
    printf("\n");
}
void deleteHead(LinkedList* list)
{
    if(list->head == NULL)
    {
        return;
    }
    else {
        Node * temp = list->head;
        list->head = temp->next;
        free(temp);
    }
}
// void deleteTail(LinkedList* list)
// {
//     Node * tmp1 = list ->head;
//     Node * tmp2 = list -> head;
//     if()
//     while(tmp2->next !=NULL)
//     {
//         tmp2->next;
//     }

// }
//Hàm main
int main(){
    LinkedList list;
    init(&list);
    //Tạo danh sách tự động
    for(int i = 0; i < 10; i++)
       insertHead(i, &list); 
    //In danh sách
    deleteHead(&list);
    printList(&list);
    return 0;
}
