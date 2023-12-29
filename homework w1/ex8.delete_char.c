#include <stdio.h>
// huytrao on the coding
void DeleteArr(char arr[], int n) { 
    int len = 0;
    while(arr[len] != '\0') { // tim do dai cua chuoi
        len++;
    }

    if (n >= 0 && n < len) { //  tim vi tri cua mang
        for(int i = n; i < len-1; i++) {
            arr[i] = arr[i+1]; // di chuyen lan luot phan tu o vi tri i+i sang i
        }
        arr[len-1] = '\0'; // gian gia chi ket thuc cho gia tri dau
    } 
}

int main() {
    int n;
    char arr[1000];
    scanf("%s",arr); 
    scanf("%d",&n); 
    DeleteArr(arr, n); // thuc thi mang
    printf("\n%s\n", arr);  // in mang ra

    return 0;
}
