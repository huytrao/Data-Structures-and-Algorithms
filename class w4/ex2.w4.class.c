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

void bubbleSort(int array[], int n,int *comp,int *swap) // ham buble short
{
    *comp =0;
    *swap =0;
    for (int i=0;i<n;i++) // cho chạy vòng lặp quét các phần tử thứ nhất
    {
        for (int j=i+1;j<n;j++) // quét các phần tử sau đó để mạnh hơn
        {
            *(comp) ++;
            if(array[j] < array[i]) //nếu phần tử trước bé hơn phần tử sau thì ododir vị trí 
            {
                *(swap) ++;
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
    int arr[100000];
    int n;
    scanf("%d",&n);
    float avgcomp[6]={0};
    float avgswap[6]={0};
    int comp[21]={0};
    int swap[22]={0};
    int comps;
    int swaps;
    int k[6] = {10,25,50,100,1000,10000};
    int min = -n*1000;
    int max = n*1000;
    for (int i=0;i<6;i++){
 
    for (int l=0;l< k[i];l++)
    {
    initializeArray(arr,n,min,max); // hàm sinh mảng giá trị từ -900 đến 900
    bubbleSort(arr,n, &comps ,&swaps);// ham doi vi tri
    comp[i] = comp[i] + comps;
    swap[i] = swap[i] + swaps;
    }
    avgcomp[i] = comp[i]/k[i];
    avgswap[i]= swap[i]/k[i];
}

    float average =0;
    printf("Observation: ");
    for(int i=0;i<6;i++)
    { 
        printf("%d ",i +1);
    }
    printf("\n swaps: ");
    for(int i=0;i<6;i++)
    { 
        printf("%0.3f ",avgswap[i]);
    }
        printf("\n comps: ");
    for(int i=0;i<6;i++)
    { 
        printf("%0.3f ",avgcomp[i]);
    }

}