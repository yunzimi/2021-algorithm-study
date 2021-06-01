#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<limits>

typedef long long ll;

using namespace std;

const ll INF = numeric_limits<ll>::max();
int n, m;
int start, last;

vector<pair<int,int>> adj[11111];

const int MAX_V = 1111111111;

// start에서 last까지
// limits 이하로 도착할 수 있는가
bool decision(int limits){
    queue<int> q;
    q.push(start);

    vector<bool> visited(n,false);
    visited[start] = true;

    while(!q.empty()){
        int here = q.front();
        q.pop();
        if(here == last) return true;

        for(int i=0; i< adj[here].size(); i++){
            int next = adj[here][i].first;
            int nextCost = adj[here][i].second;

            if(!visited[next] && limits <= nextCost){
                q.push(next);
                visited[next] = true;
            }
            
        }
    }

    return false;
}

int main(){
    cin >> n >> m;
    
    
    for(int i=0; i<m; i++){
        int a, b;
        ll c;
        cin >> a >> b;
        a--,b--;
        cin >> c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    cin >> start >> last;
    start--, last--;

    int lo = 0, hi = MAX_V;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(decision(mid)) lo = mid;
        else hi = mid;
    }
    
    cout << lo << endl;
}


