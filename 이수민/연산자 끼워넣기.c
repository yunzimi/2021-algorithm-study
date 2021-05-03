#include <stdio.h>
#include <stdlib.h>
int n,m[5],arr[13],max=-1000000001,min=1000000001,i;
void f(int index, int sum, char c, int plus, int minus, int mul, int div)
{
    if(plus > m[1] || minus > m[2] || mul > m[3] || div > m[4]) return ;
    if(c=='+')
    {
        sum += arr[index];
    }
    else if(c=='-')
    {
        sum -= arr[index];
    }
    else if(c=='*')
    {
        sum *= arr[index];
    }
    else
    {
        if(sum < 0)
        {
            sum = -sum;
            sum /= arr[index];
            sum = -sum;
        }
        else sum /= arr[index];
    }
    if(index == n)
    {
        max = max < sum ? sum : max;
        min = min > sum ? sum : min;
        return;
    }
    index++;
    f(index,sum,'+',plus+1,minus,mul,div);
    f(index,sum,'-',plus,minus+1,mul,div);
    f(index,sum,'*',plus,minus,mul+1,div);
    f(index,sum,'/',plus,minus,mul,div+1);

}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=1;i<=4;i++)
    {
        scanf("%d",&m[i]);
    }
    f(2,arr[1],'+',1,0,0,0);
    f(2,arr[1],'-',0,1,0,0);
    f(2,arr[1],'*',0,0,1,0);
    f(2,arr[1],'/',0,0,0,1);

    printf("%d\n%d",max,min);
    return 0;
}
