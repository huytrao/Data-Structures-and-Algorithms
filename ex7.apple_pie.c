#include <stdio.h>
#include <string.h>
// huytrao on the coding
int char_to_num(char arr[100][11], int k) { // Ham lay 2 gia tri dau cua chuuoi va chuyen thanh so
    int num1 = arr[k][1] - '0';
    int num = arr[k][0] - '0';
    
    if (num == 0) {
        return num1;
    } else {
        return num * 10 + num1;
    }
}
void InsertArr(char arr[][11], int *n, int m, char value[][11]) { // ham insert gia tri vao arr
    for(int i = 0; i < m; i++) {        // tao vong lap de gan gia tri value vao cho chong
        int value_num = char_to_num(value, i);  // doi 2 ky tu dau cua gia tri ra so
        int l = *n - 1;//  gan chieu dai de chay vong lap
        int dem = 0; // gan bien dem de dung vong lap while
        int c=0;
    while(dem ==0)
    {
        if(value_num <= char_to_num(arr,c)){ // kiem tra neu gia tri 2 so dau nho hon chuoi thi in sert
        while (l >= c) {
            strcpy(arr[l+1], arr[l]);
            l--;
        }
        strcpy(arr[c], value[i]); 
        (*n)++; // tang kich thuoc mang
        dem++; // dem vao de dung vong lap
        } else
        {if(c== *n) // truong hop quet het mang van khong tim duoc so lon nhat thi insert o cuoi
            {
                strcpy(arr[c], value[i]); 
                dem++;
                (*n)++;
            }
            c++;
        }
    } 
     

    }
}


int main() {
    int n;
    char arr[100][11];
    char value[100][11];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    int m;
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        scanf("%s", value[i]);
    }
    // printf("%d \n%d \n", char_to_num(arr,0), char_to_num(value,1));
    InsertArr(arr, &n, m, value);  // ham insert chuoi
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("\n%s", arr[i]); // in ra ket qua
    }
    
    return 0;
}
