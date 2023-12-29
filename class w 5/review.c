// câu 1 chèn code c trong hàm f() và main()
// để đếm bước so sánh, gán của hàm f() sau
#include <stdio.h>
int f(int a[][2],int m,int n)
{
    int flag;
    for(int i=0;i<m;i++)
    {
        flag=0;
        for(int j=0;j<n;j++)
        {
            if(a[i][j]<0)
            {
                flag =1;
                if(flag ==0)
                {
                    return 0;
                }
            }
            return 1;

        }
    void main(){
        int a[3][2]= {{1,-1},{2,-2},{3,-3}}
        if(f(a,3,2))
        {
            printf("Yes")
        }
    }
    }
}
// câu 2 đếm số phép son sánh và hoán vị theo thừng vòng và tổng kết của thuật toán sau (n là số phần tử của mảng a)
void f(int a[],int n)
{
    int i,j;
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[j-1]>=a[j])
            {
                int temp = a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}
int main()
{
    9,14,8,7,10,9,4
}
// câu 3 Hãy cài đặt thuật toán chỉnh sửa bubble sort để sắp xếp mảng theo thứ tự giảm dần bằng cách thay vì cho phần tử lớn nỗi lên thì ta cho chúng chìm xuống
// câu 4 Cài đặt hàm để kiểm tra 1 mảng số nguiyeen có phần tử trùng nhau hay không sau đó đếm số bước cụ thể của thuật toán dựa trên mảng Ơ4,2,5,1,3,5 và cho biết thuật toán có độphức tạp là gì?
