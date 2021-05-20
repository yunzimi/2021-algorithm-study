#include <stdio.h>
#include <stdlib.h>
int parent[1000001];
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

int equals_parent(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);

    if(a == b) return 1;
    else return 0;
}
int main()
{
    int n,m,a,b,c;
    scanf("%d %d",&n,&m);
    for(int i=0; i<=n; i++) parent[i] = i;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a == 0)
        {
            union_parent(b,c);
        }
        else
        {
            if(equals_parent(b,c))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
