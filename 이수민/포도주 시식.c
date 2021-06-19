#include <stdio.h>
#include <stdlib.h>
int n, arr[10001],max,dp[3][10001];
int main()
{

    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    if(n == 1)
    {
        printf("%d",arr[0]);
    }
    else if(n == 2)
    {
        printf("%d",arr[0]+arr[1]);
    }
    else
    {
        dp[1][0] = dp[2][0] = arr[0];
        dp[1][1] = arr[1];
        dp[2][1] = arr[0]+arr[1];
        for(int i=2; i<n; i++)
        {
            int num = 0;
            for(int j=0; j<i-1; j++)
            {
                num = num < dp[1][j] ? dp[1][j] : num;
                num = num < dp[2][j] ? dp[2][j] : num;
            }
            dp[1][i] = arr[i] + num;
            dp[2][i] = arr[i] + dp[1][i-1];
        }
        for(int i=0; i<n; i++)
        {
            max = max < dp[1][i] ? dp[1][i] : max;
            max = max < dp[2][i] ? dp[2][i] : max;
        }
        printf("%d",max);
    }
    return 0;
}
