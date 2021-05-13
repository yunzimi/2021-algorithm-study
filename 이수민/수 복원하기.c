#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,a;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&a);
        for(int j=2;;j++)
        {
            int cnt = 0;
            while(a%j == 0)
            {
                a /= j;
                cnt++;
            }

            if(cnt)
            {
                printf("%d %d\n",j,cnt);
            }
            if(a == 1) break;
        }
    }
    return 0;
}
