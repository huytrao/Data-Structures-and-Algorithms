#include <stdio.h>
#include <stdlib.h>

// hàm tính tổng S = 1/1 ... + 1/n
float S_1(int n)
{
    if (n==1)
        return 1;
    return S_1(n-1) + 1/n;
}
// hàm tính tổng S = 1/2 ... + 1/2*n
float S_2(int n)
{
    if (n==1)
        return 1/(2*1);
    return S_1(n-1) + 1/(2*n);
}
// hàm tính tổng S = 1/2 ... + n/(1+n)
float S_3(int n)
{
    if (n==1)
        return 1/2;
    return S_1(n-1) + n/(1+n);
}
// hàm tính tổng f(n) = 6*f(n-1) - 9*f(n-2)

float f(int n)
{
    if (n==1)
        return 2;
    if (n==2)
        return 3;
    return f(n) = 6*f(n-1) - 9*f(n-2);

}
int main()
{
    
}
