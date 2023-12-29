#include <stdio.h>
#include <stdlib.h>

int sum(int a[], int n){
    if (n==1)
        return a[0];
    return sum(a,n-1) + a[n-1];
}
base case xãy ra khi number = 1
Xác định kết quả (output) của hàm ứng với BASE CASE là phần tử đầu tiên trong mảng
b 3 trước base case là trường hợp n = 2
sum= a[0] + a[1]
trường hợp trước number bằng 2 là 3 
tường hợp đứng trước number bằng 3 là 
sum  = a[0]+ a[1]+a[2]
