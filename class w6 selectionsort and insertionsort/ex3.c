#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    } 
}

// ham insertion sort
void insertionSort(int arr[], int n,int *comps,int *shift){
    (*comps)=0;
    (*shift)=0;
    int i, key, j;
    for(int i=0;i<n;i++){
    // đặt biến tạm để chạy vòng lặp
    key =arr[i];
    //đặt biến đếm j để lọc các phần tử lơn hơn 
    j=i-1;
    // chạy vòng lặp
    while(j>=0 && key < arr[j])
    {
        (*comps)++;
        // gán biến lùi về một đơn vị
        (*shift)++;
        arr[j+1]= arr[j];
        // lùi gái trị key về một đơn vị nếu nó bé hơn
        arr[j]=key;
        j--;
    }
    // trường hợp vào so sánh không thỏa khi trong vòng while để tăng comps()
    if(j!=0){
        (*comps)++;
    }



}
}

void main(){
    int comps = 0;
    int shift=0;
	int n = 10;
	int arr[5] = {12, 11, 13, 5, 6};
    // thực thi hàm
    insertionSort(arr,n,&comps,&shift);
   for(int i=0;i<n;i++)
   {
    printf(" %d",arr[i]);
   }
   // in ra kết quả
	printf("\n số phép so sánh là %d\n",comps);
    printf("\n số phép dời là %d\n",shift);
}
