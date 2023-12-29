#include <stdio.h>

int linearSearch(int n, double arr[], double value) // chuyn doi kieu du lieu mang va gia tri tim kiem
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int main()
{   
    double arr[1000]; // chuyen doi kieu du lieu ar
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &arr[i]); //su dung long float de in ra ket qua
    }
    double value; // khai bao gia tri can chen la kieu so thuc
    scanf("%lf", &value); // su dung %lf de in ra ket qua
    int result = linearSearch(n, arr, value);
    if(result == -1)
    {
        printf("not found!"); // kiem tra ket qua
    }
    else
    {
        printf("\n %d", result);
    }
    return 0; 
}
