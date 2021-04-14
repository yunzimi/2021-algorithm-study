#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int ans = 0;
    int lcs[1001][1001] = {0, };
    string a, b;
    cin >> a >> b;
    int as, bs;
    as = a.length();
    bs = b.length();
    for(int i=1; i <= as; i++){
        for(int j=1; j <= bs; j++){
            if(a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            ans = max(ans, lcs[i][j]);
        }
    }
    cout << ans;
}
