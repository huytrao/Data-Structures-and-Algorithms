#include <stdio.h>
#include <string.h>

int CheckOrder(char arr[1000]) // ham kiem tra mang co phai xap xep co thu tu khong
{
    int dem =0;
    for(int i=1;i<strlen(arr);i++)
    {
        if(arr[i-1]> arr[i])
        {
            dem ++;
        }
    }
    if(dem ==0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int linearSearch(char arr[],char value) // ham tim kiem tuyen tinh trong order arr
{
    for(int i=0;i<strlen(arr);i++) // quet tung phan tu trong mang tu vi tri 0
    {
        if(arr[i]==value) // so sanh cac phan tu neu trung tra ve vi tri
        {
            printf("step linear: %d ",i+1 );
            return i;
            
        }
    }
    int n= strlen(arr);
    printf("step linear: %d ",n );
    return -1; // sai tra ve false
}
int binarySearch(char arr[], char value) {
    int left = 0, right = strlen(arr) - 1;// ham tim kiem
    int count =0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        count++;
       
        if (arr[mid] == value){
            printf("\nstepbinary %d",count); // kiem tra co o chinh giua hay khong
            return mid;
        }
        
        if (arr[mid] < value){ // kiem tra xem co lon hon gia tri hay khong neu lon hon doan sau bo
            left = mid + 1;
        }
      
        else{
            right = mid - 1;
        }
    }

    printf("\nstepbinary %d",count); // in ra so buoc
    return -1;
}
int main()
{
    char arr[1000];
    char value;
    scanf("%s", arr);
    getchar();
    scanf("%c", &value);
    if(CheckOrder(arr) == -1)
    {
        printf("Not Order");
    }
    else{
     int temp_1 = linearSearch(arr, value);
     int temp_2 = binarySearch(arr,value) ;
     printf("\n linear index: %d",temp_1);
     printf("\n binary index: %d",temp_2);
    }

}
