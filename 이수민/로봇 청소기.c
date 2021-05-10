#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,r,c,d,i,j,arr[51][51],cnt=0,t,dd,dx,dy;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&r,&c,&d);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    while(1)
    {
        if(arr[r][c] == 0)
        {
            arr[r][c] = -1;
            cnt++;
        }
        dd = d;
        dx = r;
        dy = c;
        for(t=1; t<=4; t++)
        {
            if(d == 0)
            {
                if(arr[r][c-1] == 0)
                {
                    c--;
                    d = 3;
                    break;
                }
                else d = 3;
            }
            else if(d == 1)
            {
                if(arr[r-1][c] == 0)
                {
                    r--;
                    d = 0;
                    break;
                }
                else d = 0;
            }
            else if(d == 2)
            {
                if(arr[r][c+1] == 0)
                {
                    c++;
                    d = 1;
                    break;
                }
                else d = 1;
            }
            else if(d == 3)
            {
                if(arr[r+1][c] == 0)
                {
                    r++;
                    d = 2;
                    break;
                }
                else d = 2;
            }
        }
        if(dd == d && dx == r && dy == c)
        {
            if(d == 0)
            {
                if(arr[r+1][c] == 1) break;
                else r++;
            }
            else if(d == 1)
            {
                if(arr[r][c-1] == 1) break;
                else c--;
            }
            else if(d == 2)
            {
                if(arr[r-1][c] == 1) break;
                else r--;
            }
            else if(d == 3)
            {
                if(arr[r][c+1] == 1) break;
                else c++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
