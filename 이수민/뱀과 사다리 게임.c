#include <stdio.h>
#include <stdlib.h>
int map[101],arr[101][101],min=99999;
void f(int index, int num)
{
    if(index >= 100)
    {
        min = min > num ? num : min;
        return ;
    }

    if(map[index] <= num) return ;
    map[index] = num;

    for(int i=1;i<=100;i++)
    {
        if(arr[index][i] == 1)
        {
            f(i,num);
            return ;
        }
    }

    for(int i=6;i>=1;i--)
    {
        f(index+i,num+1);
    }
}
int main()
{
    int i,n,m,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=100;i++) map[i] = 999;
    for(i=1;i<=n+m;i++)
    {
        scanf("%d %d",&a,&b);
        arr[a][b] = 1;
    }

    for(i=6;i>=1;i--)
    {
        f(1+i,1);
    }
    printf("%d",min);
    return 0;
}
