#include <iostream>
#include <stdlib.h>
#include <time.h>

typedef struct Stack
{
    int a[20];
    int top;
}stack;
void init(stack* s)
{
    // gan gia tri tren cung la tru 1
    s->top = -1;
}
void push(stack *s,value)
{   s->top ++;
    s->a[s->top] = value;
}

int  get(stack *s)
{

}
int Sinhmang(int arr[],int n)
{
    srand(null);
    for(int i=0;i<n;i++)
    {
        
        arr[i]= rand%(11) +2;
    }
        arr[rand%(21)] =1;
}
int bothevaohop(stack *s,int arr[])
{
    int i=0;
    while(i<=20)
    {
        if(a[i]==1)
        {
            push(s,arr[i]);
            return 0;
        }
        push(s,arr[i]);
        i++
    }
}
int get(stack* s)
{
    return (s->a[(s->top)--]);
}
int recur(*s)
{
    if(s->top ==0)
    {
        return s->a[0];
    }
    return get(s) + recur(s);
}
int main()
{
    srand(NULL)time(&t);
    Stack s
}