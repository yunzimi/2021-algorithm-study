#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#define endl '\n'
typedef long long ll;

using namespace std;

const int INF = 0x7FFFFFFF;
int n, m;

vector<int> arr;
vector<int> visited;
vector<int> finished;
vector<int> ans;

int cnt;
void dfs(int here){
    visited[here]++;
    int next = arr[here];
    if(visited[next] == 0) dfs(next);
    else if(finished[next] == 0){
        cnt++;
        for(int i = next; i != here; i = arr[i]){
            cnt++;
        }
    }

    finished[here] = 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cnt = 0;
        arr = vector<int>(n+1, 0);
        visited = vector<int>(n+1, 0);
        finished = vector<int>(n+1, 0);
        for(int i=1; i<=n; i++)
            cin >> arr[i];

        for(int i =1; i<=n; i++){
            if(visited[i]) continue;
            dfs(i);
        }
        cout << n - cnt << endl;
    }
    return 0;
}
