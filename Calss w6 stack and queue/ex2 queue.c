#include <stdio.h>
#define MAX 5

typedef struct {
    int head, tail;
    int a[MAX];
} Queue;

void init(Queue* q) {
    q->head = 0;
    q->tail = -1;
}
//  kiểm tra xem full chưa
int isFull(Queue *q)
{
     return(q->tail - q->head == MAX);
}
// kiểm tra que có rỗng không
int isEmpty(Queue *q)
{
    return ( q->tail <= q-> head  );
}
// chèn giá trị vào vị trí đuôi
void put(Queue* q, int value)
{
    q->a[++q->tail] = value;
}
// lấy ra giá trị ban đầu và giảm một đơn vị
int get(Queue* q)
{
    int temp = q->a[q->head];
    q->head ++;
    return temp;
}
// hiển thị QUEUe
void displayQueue(Queue*q)
{
    for(int i=q->head;i<=q->tail;i++)
    {
        printf("%d ",q->a[i]);
    }
}

int main() {
    Queue q;
    init(&q);
    int num[6] = {1,-2,3,-4,5,-6};
    // push
    printf("MAX = %d\n\n", MAX);
    printf("PUT\n");
    // thục hiện việc put giá trị
    for (int i = 0; i < 6; i++){
        printf("put %d: \n",num[i]);
        // kiểm tra hàm có full khi put giá trị vào không
        if(!isFull(&q)){
            put(&q,num[i]);
            displayQueue(&q);
            printf("\n");
        }
        else
            printf("Queue is full. \n\n");
    }
    // lấy giá trị ban đầu
    printf("GET\n");
    int i = 0;
    // kiểm tra hàm có rông không  để lấy từng giá trị bằng  hàm get
    while (!isEmpty(&q)) {
        printf("get %d: %d\n",i, get(&q));
        displayQueue(&q);
        i++;
        printf("\n");
     }
    return 0;
}