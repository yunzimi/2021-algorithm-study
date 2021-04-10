#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long ll;

using namespace std;

const int MAX = 987654321;

const int dy[4] = {0,0,1,-1};
const int dx[4] = {1,-1,0,0};

int n;
int bamboo[511][511];

int cache[511][511];
bool visited[511][511];

// y, x에서 시작해서 이거 제일 많이 먹을 수 있는 경로 날짜 반환 
int func(int y, int x){
	// 기저 사례는 따로 하지 않음
	// ret = 1이 기저가 됨 
	int &ret = cache[y][x];
	if(ret != -1) return ret;
	
	ret = 1;
	visited[y][x] = true;
	
	for(int i=0; i<4; i++){
		int nextY = y + dy[i], nextX = x + dx[i];
		if(nextY < 0 || nextY > n || nextX > n || nextX < 0) continue;
		
		if(bamboo[nextY][nextX] > bamboo[y][x]){
			ret = max(ret, func(nextY, nextX) + 1);
		}	
	}
	
	return ret;
}

int main(int argc, char** argv) {
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j =0; j<n; j++){
			cin >> bamboo[i][j];
		}
	}
	
	memset(cache,-1,sizeof(cache));
	memset(visited, false, sizeof(visited));
	int ret = 0;
	for(int i =0; i<n; i++){
		for(int j=0; j<n; j++){
			if(visited[i][j]) continue;
			
			ret = max(ret ,func(i,j));
		}
	}
	
	cout << ret << endl;
	
	return 0;
}
