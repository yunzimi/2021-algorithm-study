#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x,y;
}st;
st arr[100000],sort[100000];

void mergesort(int left, int right)
{
    int mid = (left+right)/2;
    int i = left;
    int j = mid+1;
    int k = left;
    int t;

    while(i<=mid && j<=right)
    {
        if(arr[i].x < arr[j].x)
        {
            sort[k].x = arr[i].x;
            sort[k].y = arr[i].y;
            i++;
        }
        else
        {
            sort[k].x = arr[j].x;
            sort[k].y = arr[j].y;
            j++;
        }
        k++;
    }

    if(i>mid)
    {
        for(t=j; t<=right; t++)
        {
            sort[k].x = arr[t].x;
            sort[k].y = arr[t].y;
            k++;
        }
    }
    else
    {
        for(t=i; t<=mid; t++)
        {
            sort[k].x = arr[t].x;
            sort[k].y = arr[t].y;
            k++;
        }
    }

    for(t=left; t<=right; t++)
    {
        arr[t].x = sort[t].x;
        arr[t].y = sort[t].y;
    }
}
void merge(int left, int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        merge(left,mid);
        merge(mid+1,right);
        mergesort(left,right);
    }
}
int main()
{
    int t,i,j,n,x,y,cnt;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        for(j=0; j<n; j++)
        {
            scanf("%d %d",&arr[j].x,&arr[j].y);
        }
        merge(0,n-1);
        x = arr[0].x;
        y = arr[0].y;
        cnt=1;
        for(j=1; j<n; j++)
        {
            if(arr[j].y < y)
            {
                cnt++;
                x = arr[j].x;
                y = arr[j].y;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
