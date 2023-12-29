#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

// Khai báo cấu trúc dữ liệu client
struct client
{
    // khai báo client 
    int id;
    int status_reg;
};

// Khai báo cấu trúc dữ liệu Queue
typedef struct {
    int head, tail;
    struct client arr[MAX];
} Queue;

// Hàm khởi tạo Queue
void init(Queue* q) {
    q->head = 0;
    q->tail = -1;
}

// Hàm kiểm tra xem Queue có đầy không
int isFull(Queue *q)
{
    return (q->tail - q->head == MAX);
}

// Hàm kiểm tra Queue có rỗng không
int isEmpty(Queue *q)
{
    return (q->tail <= q->head);
}

// Hàm chèn giá trị vào cuối Queue
void put(Queue* q, int number_user)
{
    // thực hiện thêm phía sau tail
    int dem=q->tail;
    for(int i = dem; i <dem + number_user; i++)
    {
        // nếu chưa đầy thì chèn vào với giá trị id là bằng tail +1;
        if (!isFull(q)) {
            q->tail++;
            q->arr[q->tail].id = q->tail + 1;
            q->arr[q->tail].status_reg = 1;
        } else {
            printf("Cannot Insert\n");
        }
    }
}

// Hàm lấy ra giá trị từ đầu Queue và giảm một đơn vị head
struct client get(Queue* q)
{
    // khai báo biến client và lấy client đầu trong danh sách.
    struct client temp = q->arr[q->head];
    q->head++;
    return temp;
}

// Hàm hiển thị Queue
void displayQueue(Queue*q)
{
    printf("List of customers joined\n");
    printf("Client_Id\n ");
    for(int i = q->head; i <= q->tail; i++)
    {   // in ra id của khách hàng  nếu khách hàng không cancel
        if(q->arr[i].status_reg == 1)
        {   
            printf("%d ", q->arr[i].id);
        }
    }
    printf("\n");
}

// Hàm hủy đăng ký của một khách hàng dựa trên ID
void cancelRegistration(Queue *q, int id_delete)
{   // khai báo biến kiểm tra để kiểm tra có tồn tại khách hàng trong hàng đợi không
    int check = 0;
    for(int i = q->head; i <= q->tail; i++)
    {   // nếu tồn tại khách hàng trong hàng đợi thì đặt lại bằng 1 và thực hiện đặt lại giá rtij tham gia bằng 0
       if(q->arr[i].id == id_delete)
       {
        check = 1;
        q->arr[i].status_reg = 0;
       }
    }
    if(check == 0)
    {
        printf("Cancel not successful\n");
    } else 
    {
        printf("Cancel successful\n");
    }
}

int main()
{
    Queue q;
    init(&q);
    // chọn số lượng khách hàng đăng kí là 10
    put(&q, 10);
    printf("danh sách khách hàng sau khi thêm 10 khách hàng\n");
    displayQueue(&q);
    // Gọi hàm hủy đăng ký
    int id_to_cancel = 5; // Thay đổi ID cần hủy đăng ký tại khách hàng thứ 5
    cancelRegistration(&q, id_to_cancel);
     printf("\n danh sách khách hàng sau khi khách hàng thứ 5 cancel\n");
    displayQueue(&q);
    // lấy ra khách hàng đầu tiên
    printf("Khách hàng đầu trong vị trí hàng đợi \nID\n%d\n",get(&q).id);
    displayQueue(&q);
    return 0;
}
