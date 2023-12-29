#include <stdio.h>
#include <string.h>

void insertchar(char str[], char ch, int pos) { // insert char  vao vi tri can chen
    int len = strlen(str);
    for (int i = len; i >= pos; i--) {
        str[i+1] = str[i];
    }
    str[pos] = ch;
}

int insert_ASCII(char arr[]) // ham tim kiem tuyen tinh trong order arr
{
    int n=strlen(arr); // kiem tra gia tri cuoi cung trong mang
    if(arr[n-1] != 'z')
    {
        printf("z at 25 is missing!");
        insertchar(arr, 'z', 25);
        arr[25+1]='\0';
        return 0;
    }

    if(arr[0] == 'a')
    {
    for(int i=1;i<strlen(arr)-1;i++) // quet tung phan tu trong mang tu vi tri 0
    {
        if(arr[i] != arr[i+1]-1) // // kiem tra tung phan tu co bang tri so phan tu lien ke +1 khon
        {
            printf("find %c at %d is missing!", (arr[i] +1), i+1); 
            insertchar(arr,arr[i]+1,i+1);
            break;
        }
    }// in ra vi tri 
    }
    else{

        printf("a at 0 is missing!");
        insertchar(arr, 'a', 0);
        return 0;
    }
    return 0; // sai tra ve false
    
}
int main()
{
    char arr[30];
    scanf("%s",arr);
    insert_ASCII(arr); // thu thi ham 
    printf(" \n %s", arr); // in ra ket qua
    return 0;
}
