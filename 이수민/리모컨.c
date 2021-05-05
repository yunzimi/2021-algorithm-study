#include <stdio.h>
#include <stdlib.h>
int arr[10],min,n,m,a;
void f(int num, int cnt)
{
    if(num > 9999999) return;
    int k = abs(num - n);
    min = min > k + cnt ? k + cnt : min;
    for(int i=0;i<=9;i++)
    {
        if(num == 0 && i == 0) continue;
        if(!arr[i]) f(num * 10 + i,cnt + 1);
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&a);
        arr[a] = 1;
    }
    min = abs(n - 100);
    for(i=0;i<=9;i++)
    {
        if(!arr[i]) f(i,1);
    }
    printf("%d",min);
    return 0;
}
