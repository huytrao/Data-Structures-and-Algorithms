#include <stdio.h>
int f(int n)
{
    // cho f bằng 1
    if(n==1)
        return 1;
    int f = 1;
    // chạy vòng for từ i tới n
    for(int i=2;i<n;i++)
    {
        f= f*2;
    }
    return f;
}
float g(int n)
{
    // đặt base case và trả về kết quả
    if (n==1)
        return 1.0;
    float g = 1.0;
    // thực hiện chạy vòng for 
    for(int i=2;i<n;i++)
    {
        g= g + i*i;
    }
    return g;
}
// chạy hàm f trả về kết quả đúng

