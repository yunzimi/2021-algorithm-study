#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

typedef long long ll;

using namespace std;

const int INF = 987654321;

const int dy[4] = {0,0,-1,1};
const int dx[4] = {1,-1,0,0};

const int hy[8] = {2,1,-1,-2,-2,-1,1,2};
const int hx[8] = {1,2,2,1,-1,-2,-2,-1};



int adj[211][211];
int W, H;

bool visited[211][211][33];



// y,x 에서 k번 말움직임으로 목적지에 최단거리로 도착할 수 있는 움직임 수
int solve(int startY, int startX, int kk){
	
	queue<pair<pair<int,int>, pair<int,int>>> q;
	q.push({{0, kk}, {startY,startX}});
	
	while(!q.empty()){
		pair<pair<int,int>, pair<int,int>> here = q.front();
		q.pop();
		
		int dist  =here.first.first;
		int k = here.first.second;
		int y = here.second.first, x = here.second.second;
		

		if(y == H -1 && x == W - 1) return dist;
		
		if(k > 0){
			for(int i =0; i<8; i++){
				int nextY = y + hy[i], nextX = x + hx[i];
				if(nextY < 0 || nextY >= H || nextX >= W || nextX < 0) continue;
				if(adj[nextY][nextX] == 1) continue;
				
				if(visited[nextY][nextX][k-1]) continue;
				
				q.push({{dist+1, k-1}, {nextY,nextX}});
	
				visited[nextY][nextX][k-1] = true;
		
				
			}
		}
		
		for(int i=0; i< 4; i++){
			int nextY = y + dy[i], nextX = x + dx[i];
			if(nextY < 0 || nextY >= H || nextX >= W || nextX < 0) continue;
			if(adj[nextY][nextX] == 1) continue;
			if(visited[nextY][nextX][k]) continue;

			q.push({{dist+1, k}, {nextY,nextX}});	
			visited[nextY][nextX][k] = true;
		}
		
	}
	return -1;
}

int main(int argc, char** argv) {
	int k;
	cin >> k;
	cin >> W >> H;
	for(int i=0; i<H; i++)
		for(int j =0; j<W; j++){
			cin >> adj[i][j];
		}
		
	memset(visited, false, sizeof(visited));
	int ans = solve(0,0, k);
	
	cout << ans << endl;
	
	return 0;
}
