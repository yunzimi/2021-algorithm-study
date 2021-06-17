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

const int INF = 9876541;

int n, q, r;
vector<int> adj[111111];
bool visited[111111];

int cache[111111];

// dfs
int func(int here){
    visited[here] = true;
    int &ret = cache[here];
    if(ret != -1) return ret;
    ret = 1;
    for(int i=0; i< adj[here].size(); i++){
        int next = adj[here][i];
        if(!visited[next]){
            ret += func(next);
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int n, r, q;
    cin >> n >> r >> q;
    for(int i =0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(cache, -1, sizeof(cache));
    func(r);
    for(int i=0; i<q; i++){
        int t;
        cin >> t;
        cout << cache[t] << endl; 
    }
}


