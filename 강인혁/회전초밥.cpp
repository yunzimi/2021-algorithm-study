#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<limits>
#include<cstring>
#include <cmath>

typedef long long ll;
#define endl '\n'

using namespace std;

const int INF = 0X7FFFFFFF;

int n, d,k,c;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    cin >> n >> d >> k >> c;
    vector<int> visited(3333333, false);
    vector<int> sushi(n, 0);
    for(int i=0; i<n; i++) cin >> sushi[i];

    int curCnt = 0;
    for(int i=0; i<k; i++){
        visited[sushi[i]]++;
        if(visited[sushi[i]] == 1) curCnt++;
    }

    int ret = curCnt;
    for(int start =0, end = k-1; start < n; start++){
        end++;
        if(end == n) end = 0;
        visited[sushi[end]]++;
        if(visited[sushi[end]] == 1) {
            curCnt++;
        }
        visited[sushi[start]]--;
        if(visited[sushi[start]] == 0) {
            curCnt--;
        }
        if(visited[c] == 0) curCnt++;

        ret = max(curCnt, ret);
        
        if(visited[c] == 0) curCnt--;
    }

    cout << ret << endl;
}



