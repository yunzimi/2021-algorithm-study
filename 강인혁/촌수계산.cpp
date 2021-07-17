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

vector<int> adj[111];
bool visited[111];

int ans = -1;
// here에서 dest로 가는 길이
void dfs(int here, int dest, int cnt){
    if(here == dest){
        ans = cnt;
        return;
    }
    visited[here] = true;
    for(int i=0; i< adj[here].size(); i++){
        int next = adj[here][i];
        if(!visited[next]) dfs(next, dest, cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int a, b;
    cin >> a >> b;
    cin >> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(a,b, 0);
    cout << ans << endl;
    
    return 0;
}
