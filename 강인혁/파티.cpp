#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>

typedef long long ll;

using namespace std;

const int INF = 987654321;

int N, M, X;

int adj[1001][1001];

// X부터 거 모든마을 그냥 다 방문해 최단거리로 
vector<int> func(int start){
	vector<int> dist(N, INF);
	
	queue<pair<int,int>> q;
	q.push({start, 0});
	dist[start] = 0;
	
	while(!q.empty()){
		int here = q.front().first;
		int cost = q.front().second;
		q.pop();
		
		if(dist[here] < cost) continue;
		
		for(int next=0; next<N; next++){
			if(adj[here][next]){
				int nextCost = cost + adj[here][next];
				if(dist[next] > nextCost){
					dist[next] = nextCost;
					q.push({next, nextCost});
				}
			}
		}
	}
	
	return dist;
	
}


// here에서 X로 가는 가장 짧은 경로를 가져와야 함 
int dfs(int here, vector<int>& dist, vector<bool>& visited){
	int &ret = dist[here];
	if(here == X-1) return ret = 0;
	
	visited[here] = true;
	ret = INF;
	
	for(int next =0; next <N; next++){
		if(adj[here][next] && !visited[next]){
			ret = min(ret, dfs(next, dist, visited) + adj[here][next]);
		}
	}
	
	return ret;
}

bool reversed[1001][1001];

int main(int argc, char** argv) {
	
	cin >> N >> M >> X;
	
	memset(adj, 0, sizeof(adj));
	for(int i=0; i<M; i++){
		int start, end, times;
		cin >> start >> end >> times;
		start--, end--;
		adj[start][end] = min(adj[start][end], times);
		
		if(adj[start][end]) adj[start][end] = min(adj[start][end], times);
		else adj[start][end] = times;
	}
	
	int ret = 0;
	// x에서 시작해서 각 마을로 가야함
	vector<int> XToOther = func(X-1);
	
	
	// 간선 다 뒤집기
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++){
			if(adj[i][j] != 0 && !reversed[i][j]){
				swap(adj[i][j], adj[j][i]);
				reversed[i][j] = reversed[j][i] = true;
			}
		}
	}
	vector<int> OtherToX = func(X-1);
	
	
	for(int i=0; i<N; i++){
		//cout << XToOther[i] << "   "<<  OtherToX[i] << endl;
		ret = max(ret, XToOther[i] + OtherToX[i]);
	}
	
	cout << ret << endl;
	
	
	return 0;
}
