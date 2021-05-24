#include <stdio.h>
#include <stdlib.h>
int n,m,parent[201],arr[201][201],ar[201],i,j;
int get_parent(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = get_parent(parent[x]);
}

void union_parent(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=1;i<=n;i++) parent[i] = i;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(arr[i][j] == 1)
            {
                union_parent(i,j);
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&ar[i]);
    }
    int isOk = 1;
    for(i=1;i<m;i++)
    {
        if(get_parent(ar[i]) != get_parent(ar[i+1]))
        {
            isOk = 0;
            break;
        }
    }
    if(isOk == 1) printf("YES");
    else printf("NO");
    return 0;
}
