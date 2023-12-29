#include <stdio.h>
#include <string.h>
// Huytraon on the coding
int compare(char arr[], char value[], int len) { // ham so sanh 2 chuoi voi cung mot do dai
    int i = 0;

    while (i < len && arr[i] != '\0' && value[i] != '\0') { // thuc hien vong lap chay den cuoi
        if (arr[i] != value[i])
            return -1;
        i++;
    }

    if (i == len)
        return 0;
    else
        return -1;
}
void SearchArr(char arr[], int n, char value[][6]) {
    int count; // bien dem tam
    int count1;// bien dem tam
    int dem[6] = {0};       // luu so luong phan tu cua moi chuoi
    int vitri[100][7] = {0}; //  luu vi tri cua moi chuoi

   

    for(int j = 0; j < n; j++) {
        count1 = 0; 

        for(int i = 0; i < strlen(arr); i++) { // tao vong lap
            if (i + strlen(value[j]) - 1 < strlen(arr)) { // kiem tra chuoi can kiem tra co o cuoi chuoi chinh khong
                if (compare(&arr[i], value[j], strlen(value[j])) == 0) { // thuc hien so sanh chuoi
                    dem[j]++;
                    vitri[j][count1] = i;
                    count1++;
                }
            }
        }

        printf("%d %s ", dem[j], value[j]); // in ra ket qua

        for(int l = 0; l < dem[j]; l++) {
     
            printf(",%d ", vitri[j][l]);
            
        }
        printf("\n");
    }
}
int main() {
    char arr[1000];
    int n;
    char value[7][6] ;
    scanf("%s",arr);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    scanf("%s",value[i]);
    }



    SearchArr(arr, n, value); // thuc thi ham

    return 0;
}