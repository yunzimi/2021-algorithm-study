#include <bits/stdc++.h>
using namespace std;

int priority(char c)
{
    if(c=='+' || c=='-') return 1;
    else if(c=='*' || c=='/') return 2;
    else return 0;
}

int main()
{
    stack<char> s;
    queue<char> q;
    char arr[101];
    int i;
    scanf("%s",arr);
    int arr_size = strlen(arr);
    for(i=0; i<arr_size; i++)
    {
        int p = priority(arr[i]);

        if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
        {
            while(!s.empty() && priority(s.top()) >= p)
            {
                q.push(s.top());
                s.pop();
            }
            s.push(arr[i]);
        }
        else if(arr[i] == '(')
        {
            s.push(arr[i]);
        }
        else if(arr[i] == ')')
        {
            while(!s.empty() && s.top()!='(')
            {
                q.push(s.top());
                s.pop();
            }
            s.pop();
        }
        else q.push(arr[i]);
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    while(!q.empty())
    {
        printf("%c",q.front());
        q.pop();
    }
    return 0;
}
