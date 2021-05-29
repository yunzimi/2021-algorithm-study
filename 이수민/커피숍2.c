#include <stdio.h>
#include <stdlib.h>
long long int arr[100001], tree[400004];
long long int init(int left, int right, int node)
{
    if(left == right) return tree[node] = arr[left];

    int mid = (left + right) / 2;
    return tree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

long long int sum(int left, int right, int start, int end, int node)
{
    if(start > right || end < left) return 0;

    if(start <= left && right <= end) return tree[node];

    int mid = (left + right) / 2;
    return sum(left, mid, start, end, node * 2) + sum(mid + 1, right, start, end, node * 2 + 1);
}

void fix(int left, int right, int key, long long int value, int node)
{
    if(key < left || key > right) return;

    tree[node] += value;

    if(left == right) return;

    int mid = (left + right) / 2;
    fix(left, mid, key, value, node * 2);
    fix(mid + 1, right, key, value, node * 2 + 1);
}


int main()
{
    int n,q,x,y,a,b;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++) scanf("%lld",&arr[i]);
    init(1,n,1);
    for(int i=0; i<q; i++)
    {
        scanf("%d %d %d %d",&x,&y,&a,&b);
        if(x > y)
        {
            int t = x;
            x = y;
            y = t;
        }
        printf("%lld\n",sum(1,n,x,y,1));

        fix(1,n,a,b - arr[a],1);
        arr[a] = b;
    }
    return 0;
}
