#include <stdio.h>
#include <stdlib.h>
int n,i,arr[1001],dp[1001],max=0,dpmax=0,j;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        max = 0;
        for(j=1;j<i;j++)
        {
            if(arr[i] > arr[j])
            {
                max = max < dp[j] ? dp[j] : max;
            }
        }
        dp[i] = max+1;
        dpmax = dpmax < dp[i] ? dp[i] : dpmax;
    }
    printf("%d",dpmax);
    return 0;
}
