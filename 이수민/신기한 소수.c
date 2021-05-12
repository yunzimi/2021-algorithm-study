#include <stdio.h>
#include <stdlib.h>
int n;
void f(int num, int count)
{
    for(int i=2; i<num; i++)
    {
        if(num % i == 0) return ;
    }

    if(count == n)
    {
        printf("%d\n",num);
        return ;
    }

    for(int i=0; i<=9; i++)
    {
        f(num * 10 + i, count+1);
    }


}
int main()
{

    scanf("%d",&n);
    for(int i=2; i<=9; i++) f(i,1);
    return 0;
}
