#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

typedef long long ll;

using namespace std;

const int INF = 987654321;

ll n, m;
vector<vector<int>> adj;

void dfs(int here, vector<int>& ans, vector<bool>& visited){
    visited[here] =true;
    for(int i=0; i< adj[here].size(); i++){
        int next = adj[here][i];
        if(!visited[next]){
            dfs(next, ans, visited);
        }
    }
    ans.push_back(here);
}

vector<int> solve(){
    vector<int> ret;
     vector<bool>visited(n+1, false);

    for(int i=1; i<=n; i++) if(!visited[i]) dfs(i, ret, visited);
    reverse(ret.begin(), ret.end());

    return ret;
}

int main(){
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
   
    for(int i=0; i <m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

   vector<int> ret = solve();
    
    for(int i=0; i<ret.size(); i++){
        cout << ret[i] << " ";
    }

    return 0;
}

