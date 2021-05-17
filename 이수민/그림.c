#include <stdio.h>
#include <stdlib.h>
int arr[501][501],cnt,num=1,max,i,j,n,m;
void f(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m || arr[x][y] != 1 ) return;

    arr[x][y] = num;
    cnt++;

    f(x-1,y);
    f(x+1,y);
    f(x,y-1);
    f(x,y+1);
}
int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(arr[i][j] == 1)
            {
                num++;
                cnt = 0;
                f(i,j);
                max = max < cnt ? cnt : max;
            }
        }
    }
    printf("%d\n%d",num - 1,max);
    return 0;
}
