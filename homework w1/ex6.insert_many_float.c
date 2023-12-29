#include <stdio.h>
//huytrao on the coding
int InsertFloat(float arr[], int *n, int m, int index[], float value[]) {
    int count=0; // tao bien dem vi khi dich chuyen thi vi tri cua index duoc chen tiep theo cung dich chuyen
    for (int c = 0; c < m; c++) {
        for (int i = *n; i >= (index[c]+count); i--) { // dich chuyen cac phan tu truoc gia tri can chen
            arr[i] = arr[i - 1]; 
        }
        arr[index[c]+count] = value[c]; //  chen gia tri vao vi tri can chen
      // tang so luong gia tri trong mang
      (*n)++; 
      count ++; // tang vi tri chen
    }
      

    return 0; // Trả về số lượng phần tử trong mảng sau khi chèn
}

int main() {
    int n;
    float arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    int m;
    int index[100];
    float value[100];

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%f %d", &value[i], &index[i]);
    }

     InsertFloat(arr, &n, m, index, value); // thuc thi ham chen so thuc

    for (int i = 0; i < n; i++) { // in ra ket qua
        printf("%f ", arr[i]); 
    }

    return 0;
}
