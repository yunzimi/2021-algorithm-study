#include <stdio.h>
#include <stdlib.h>
int tree[4000004],arr[1000001];

int init(int start, int end, int node)
{
    if(start == end)
    {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
int sum(int left, int right, int start, int end, int node)
{
    if(start > right || end < left) return 0;

    if(start <= left && right <= end)
    {
        return tree[node];
    }

    int mid = (left + right) / 2;
    return sum(left, mid, start, end, node * 2) + sum(mid + 1, right, start, end, node * 2 + 1);
}
void modify(int left, int right, int node, int key, int value)
{
    if(left > key || right < key) return;
    tree[node] += value;

    if(left == right) return;

    int mid = (left + right) / 2;
    modify(left, mid, node * 2, key, value);
    modify(mid + 1, right, node * 2 + 1, key , value);
}
int main()
{
    int n,m,a,b,c;
    scanf("%d %d",&n,&m);
    init(1, n, 1);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a == 0)
        {
            if(b > c)
            {
                int t = b;
                b = c;
                c = t;
            }
            printf("%d\n",sum(1,n,b,c,1));
        }
        else
        {
            modify(1,n,1,b,c - arr[b]);
        }
    }
    return 0;
}
