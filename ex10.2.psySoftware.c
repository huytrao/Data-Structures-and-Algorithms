#include <stdio.h>
#include <string.h>
//huytrao on the coding
int compare(char arr[], char value[], int len) { // ham so sanh hai mang
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

void SearchArr(char arr[], int n, char value[][6], int vitri[][7], int dem[]) { // ham tim kiem o bai 10.1
    for (int j = 0; j < n; j++) {
        int count1 = 0;

        for (int i = 0; i < strlen(arr); i++) {
            if (i + strlen(value[j]) - 1 < strlen(arr)) {
                if (compare(&arr[i], value[j], strlen(value[j])) == 0) {
                    dem[j]++;
                    vitri[j][count1] = i;
                    count1++;
                }
            }
        }
    }
}

void DeleteArr(char arr[], int n, char value[][6], int vitri[][7], int dem[]) { //ham  xoa mang 
    for (int j = 0; j < n; j++) {
        for (int l = 0; l < dem[j]; l++) {
            int start = vitri[j][l]; // bat dau tu vi tri
            int end = start + strlen(value[j]); 

            // Shift characters to the left to overwrite the matched substring
            while (arr[end] != '\0') { // chay tu dau toi cuoi
                arr[start] = arr[end]; // doi vi bang voi gia tri cua strlen(value[j])
                start++;
                end++;
            }

            //  giam vi tri cua cac gia tri lon hon vi tri da chuyen doi truoc do
            for (int j_1 = 0; j_1 < n; j_1++) {
                for (int l_1 = 0; l_1 < dem[j_1]; l_1++) {
                    if (vitri[j_1][l_1] > vitri[j][l]) {
                        vitri[j_1][l_1] = vitri[j_1][l_1] - strlen(value[j]);
                    }
                }
            }
        }
    }
    for (int j_1 = 0; j_1 < n; j_1++) {
            arr[strlen(arr)-strlen(value[j_1])*dem[j_1]] = '\0'; // rut gon mang
    }
}

int main() {
    char arr[1000];
    int n;
    char value[7][6];
    int vitri[7][7] = {0};
    int dem[7] = {0};

    scanf("%s", arr);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", value[i]);
    }

    SearchArr(arr, n, value, vitri, dem);
    DeleteArr(arr, n, value, vitri, dem);// thuc hien mang

    printf("\n %s \n", arr);

    return 0;
}
