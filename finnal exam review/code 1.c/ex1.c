// bài 1 với u(n)= 1/(n+(n+1)) với u(0) =1
// bai 2 

float S(int n)
{
    if (n == 0)
        return 1.0;  // Giá trị cơ sở khi n = 0

    float term = 1.0 / (n + (n + 1));  // Tính giá trị của một số hạng trong dãy
    float previous_u = S(n - 1);  // Tính giá trị u(n-1) bằng đệ quy

    return previous_u + term;  // Tính giá trị u(n) dựa trên u(n-1) và số hạng hiện tại
}
// hàm đệ quy không cần comment 

float S1(int n)
{
    if (n == 0)
        return 1.0;  // Giá trị cơ sở khi n = 0

    float sum = 1.0;  // Đặt tổng ban đầu
    float term;  // Số hạng trong dãy

    for (int i = 1; i <= n; i++)
    {
        term = 1.0 / (i + (i + 1));  // Tính giá trị của một số hạng trong dãy
        sum += term;  // Cộng số hạng vào tổng
    }

    return sum;  // Trả về tổng của dãy u(n)
}

int main()
{
    int n =10 ;

    float result = S1(n);
    printf("Gia tri u(%d) = %f\n", n, result);

    return 0;
}

// Bài 3 
// step 1: Base Case: n=0;
//step 2: Output S(0) = 1;
// step 3: S(1) = 1 +1/(1+2) = 4/3
// step 4 : S(2) =  1 +  1/3 + 1/(3+4) =49/12
