#include <stdio.h>
#include <stdlib.h>
int arr[1300000];
int main()
{
    arr[0] = 1;
    arr[1] = 1;
    int t,i,j,a,n;
    for(i=2; i*i<=1300000; i++)
    {
        if(arr[i] == 1) continue;
        for(j=i+i; j<=1300000; j+=i)
        {
            arr[j] = 1;
        }
    }
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        if(arr[n] == 0) printf("0\n");
        else
        {
            int a = 2;
            for(j=3;;j++)
            {
                if(arr[j] == 0)
                {
                    if(a < n && n < j)
                    {
                        printf("%d\n",j - a);
                        break;
                    }
                    else a = j;
                }
            }
        }
    }
    return 0;
}
