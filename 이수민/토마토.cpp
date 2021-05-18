#include <bits/stdc++.h>
using namespace std;
int arr[101][101][101],m,n,h,i,j,k,max_cnt;
typedef struct{
    int x,y,z,cnt;
}st;
int f(int x, int y, int z)
{
    if(x < 0 || x >= h || y < 0 || y >= n || z < 0 || z >= m || arr[x][y][z] != 0) return 0;
    return 1;
}
int check()
{
    for(i=0;i<h;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(arr[i][j][k] == 0) return 0;
            }
        }
    }
    return 1;
}
int main()
{
    queue<st> q;
    scanf("%d %d %d",&m,&n,&h);
    for(i=0;i<h;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                scanf("%d",&arr[i][j][k]);
                if(arr[i][j][k] == 1) q.push({i,j,k,0});
            }
        }
    }

    while(!q.empty())
    {
        st s = q.front();
        int x = s.x;
        int y = s.y;
        int z = s.z;
        int cnt = s.cnt;
        max_cnt = max(max_cnt,cnt);
        q.pop();
        if(f(x-1,y,z))
        {
            q.push({x-1,y,z,cnt+1});
            arr[x-1][y][z] = 1;
        }

        if(f(x+1,y,z))
        {
            q.push({x+1,y,z,cnt+1});
            arr[x+1][y][z] = 1;
        }

        if(f(x,y-1,z))
        {
            q.push({x,y-1,z,cnt+1});
            arr[x][y-1][z] = 1;
        }

        if(f(x,y+1,z))
        {
            q.push({x,y+1,z,cnt+1});
            arr[x][y+1][z] = 1;
        }

        if(f(x,y,z-1))
        {
            q.push({x,y,z-1,cnt+1});
            arr[x][y][z-1] = 1;
        }

        if(f(x,y,z+1))
        {
            q.push({x,y,z+1,cnt+1});
            arr[x][y][z+1] = 1;
        }
    }
    if(check()) printf("%d",max_cnt);
    else printf("-1");

    return 0;
}
