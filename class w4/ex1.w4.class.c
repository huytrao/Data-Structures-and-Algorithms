#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initializeArray(int arr[],int n, int min, int max){
    int i;
    srand(time(0));// khởi tạo seed cho hầm rand()dựa trên thời gian hiện tại.
    for(i =0;i<n;i++)
    {
        arr[i]=min + rand()% (max-min+1);
        // Sinh ngẫu nhiên giá trị trong khoảng [min,max]
    }
}

void bubbleSort(int array[], int n) // ham buble short
{
    for (int i=0;i<n-1;i++) // cho chạy vòng lặp quét các phần tử thứ nhất
    {
        for (int j=i+1;j<n;j++) // quét các phần tử sau đó để mạnh hơn
        {
            if(array[j] < array[i]) //nếu phần tử trước bé hơn phần tử sau thì ododir vị trí 
            {
                int temp;
                temp=array[j];
                array[j]=array[i];
                array[i] =temp;
            }
        }

    }
}
int main()
{
    int arr[100];
    int n;
    scanf("%d",&n);
    initializeArray(arr,n,-900,900); // hàm sinh mảng giá trị từ 0 đến 900
    bubbleSort(arr,n);
    for (int i=0;i<n ;i++) // in ra mảng
    {
        printf(" %d ", arr[i]);
    }
}