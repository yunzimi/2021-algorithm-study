#include <stdio.h>
#include <stdlib.h>
int n,m,i,j,arr[1001][1001];
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
            arr[i][j] += arr[i-1][j] >= arr[i][j-1] ?
                          arr[i-1][j] >= arr[i-1][j-1] ?
                          arr[i-1][j] : arr[i-1][j-1] : arr[i][j-1] >= arr[i-1][j-1] ?
                          arr[i][j-1] : arr[i-1][j-1];
        }
    }
    printf("%d",arr[n][m]);
    return 0;
}
