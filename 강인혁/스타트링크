#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<limits>
#include<cstring>

typedef long long ll;

using namespace std;

const int INF = 987654321;

int f,g,s,u,d;

// dijkstra
vector<int> func(int start){
    vector<int> dist(f+1, INF);
    
    priority_queue<pair<int,int>> q;
    q.push({0, start});
    dist[start] = 0;

    while(!q.empty()){
        int here = q.top().second;
        int cost = -q.top().first;
        q.pop();

        if(dist[here] < cost) continue;

        // up
        int next = here + u;
        if(next <= f){
            int nextCost = cost+1;
            if(dist[next] > nextCost){
                q.push({-nextCost, next});
                dist[next] = nextCost;
            }
        }
        // down
        next = here - d;
        if(next >= 0){
            int nextCost = cost+1;
            if(dist[next] > nextCost){
                q.push({-nextCost, next});
                dist[next] = nextCost;
            }
        }
    }

    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> f >> s >> g >> u >> d;
    f--,s--,g--;
    vector<int> ans = func(s);

    if(ans[g] == INF) cout << "use the stairs";
    else cout << ans[g];

    return 0;
}


