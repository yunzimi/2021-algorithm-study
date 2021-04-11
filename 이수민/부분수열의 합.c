#include <stdio.h>
#include <stdlib.h>
int n,s,cnt,arr[21];
void f(int index, int sum)
{
    if(sum == s)
    {
        cnt++;
    }

    for(int i=index+1;i<=n;i++)
    {
        f(i,sum+arr[i]);
    }
}

int main()
{
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=1;i<=n;i++)
    {
        f(i,arr[i]);
    }
    printf("%d",cnt);
    return 0;
}
