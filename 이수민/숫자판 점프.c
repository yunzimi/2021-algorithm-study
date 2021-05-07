#include <stdio.h>
#include <stdlib.h>
int seq,check[1000000],arr[6][6];
void f(int x, int y, int cnt,int num)
{

    if(x < 1 || x > 5 || y < 1 || y > 5) return;
    num = num * 10 + arr[x][y];
    if(cnt == 6)
    {
        if(check[num] == 1) return;
        check[num] = 1;
        seq++;
        //printf("%d\n",num);
        return;
    }
    cnt++;
    f(x-1,y,cnt,num);
    f(x+1,y,cnt,num);
    f(x,y-1,cnt,num);
    f(x,y+1,cnt,num);
}
int main()
{
    int i,j;
    for(i=1;i<=5;i++)for(j=1;j<=5;j++)scanf("%d",&arr[i][j]);
    for(i=1;i<=5;i++)for(j=1;j<=5;j++)f(i,j,1,0);
    printf("%d",seq);
    return 0;
}
