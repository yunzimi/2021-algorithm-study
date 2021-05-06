#include <stdio.h>
#include <stdlib.h>
int arr[10001];
int main()
{
    int i,j,t,n,a,b;
    for(i=2;i*i<=10000;i++)
    {

        for(j=i*2; j<=10000; j+=i)
        {
            arr[j] = 1;
        }
    }



    scanf("%d",&t);
    for(i=0;i<t;i++)
    {

        scanf("%d",&n);
        for(j=2;j<=n/2;j++)
        {
            if(!arr[j] && !arr[n-j])
            {
                a = j;
                b = n-j;
            }
        }
        printf("%d %d\n",a,b);
    }

    return 0;
}
