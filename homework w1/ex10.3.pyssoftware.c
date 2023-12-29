#include <stdio.h>
#include <string.h>

void insert_2_string(char arr[], char value[], int pos) { // ham insert de in sert value vao arr
    int i, j;

// tim do dai cua chuoi
    int len_arr = 0;
    while (arr[len_arr] != '\0') {
        len_arr++;
    }

    // tim do dai 
    int len_value = 0;
    while (value[len_value] != '\0') {
        len_value++;
    }

    // doi vi tri
    for (i = len_arr; i >= pos; i--) {
        arr[i + len_value] = arr[i];
    }
    
    // chen chuoi
    for (i = 0, j = pos; i < len_value; i++, j++) {
        arr[j] = value[i];
    }

    // ket thuc chuoi
    arr[len_arr + len_value] = '\0';
}

void del_val_in_arr(char arr[], char value[], int position) {
    int len = strlen(arr); // luu lai do dai arr
    int val_len = strlen(value);// luu lai do dai value
    int i, j;

    for (i = position; i < len - val_len + 1; i++) { // chen chuoi khi bang
        for (j = 0; j < val_len; j++) {
            if (arr[i + j] != value[j]) {
                break;
            }
        }
        if (j == val_len) {
            // Tìm thấy giá trị cần xóa
            for (int k = i; k < len - val_len; k++) {
                arr[k] = arr[k + val_len];
            }
            len -= val_len;
            i -= 1; // kiem tra lai gia tri chuoi
        }
    }

    arr[len] = '\0'; // ket thuc chuoi
}

void insertchar(char str[], char ch, int pos) { // in sert char  vao vi tri can chen
    int len = strlen(str);
    for (int i = len; i >= pos; i--) {
        str[i+1] = str[i];
    }
    str[pos] = ch;
}

int compare(char arr[], char value[], int len) { // ham so sanh 2 chuoi  neu 2 chuoi bang nhau
    int i = 0;

    while (i < len && arr[i] != '\0' && value[i] != '\0') {
        if (arr[i] != value[i])
            return -1;
        i++;
    }

    if (i == len || value[i] == '\0')
        return 0;
    else
        return -1;
}
void insertCharASII(char str[]) { // ham bien doi ky tu sang ASCII -1
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        char ch = (char)(str[i] + 1);
        insertchar(str, ch, i + 1);
    }
}

void SearchArr(char arr[], int n, char value[][6], int vitri[][100], int dem[]) { // ham tim kiem mang de tra ve vi tri
    for (int j = 0; j < n; j++) {
        int count1 = 0;

        for (int i = 0; i <= strlen(arr) - strlen(value[j]); i++) { 
            if (compare(&arr[i], value[j], strlen(value[j])) == 0) {// so sanh 2 mang 
                dem[j]++;   // tang bien dem len
                vitri[j][count1] = i;// gan luu gia tri vao value[j]
                count1++; // tang bien dem len
            }
        }
    }
}

void InsertArr(char arr[], int n, char value[][6], int vitri[][100], int dem[]) { // ham insert arr
    int original_len = strlen(arr); // luu do dai ban dau cua chuoi
    
    for (int j = 0; j < n; j++) {// ham chen vi tri string
        char value_1[100][100];
        insert_2_string(value_1[j], value[j], 0);// copy tat ca cac gia tri vao value 1
        insertCharASII(value_1[j]); // bien value1 thanh string
        
        for (int l = 0; l < dem[j]; l++) {
            int insert_pos = vitri[j][l] ;// offset
            del_val_in_arr(arr,value[j],insert_pos); // xoa gia tri trong chuoi de xoa gia tri value du thua 
            insert_2_string(arr, value_1[j], insert_pos); // chen gia tri value_1 la cac tu ASCII -1
            
            for (int j_1 = 0; j_1 < n; j_1++) { // tang vi tri cua cac bien vi tri sau neu no o phia sau chuoi
                for (int l_1 = 0; l_1 < dem[j_1]; l_1++) {
                    if (vitri[j_1][l_1] > insert_pos) {
                        vitri[j_1][l_1] += strlen(value[j]);
                    }
                }
            }
            
            // offset += strlen(value_1[j]);
        }
    }
}

int main() {
    char arr[1000];
    int n;
    char value[7][6];
    int vitri[7][20] = {0};
    int dem[7] = {0};

    scanf("%s", arr);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", value[i]);
    }

    SearchArr(arr, n, value, vitri, dem);
    InsertArr(arr, n, value, vitri, dem);

    printf("\n%s\n", arr);

    return 0;
}
