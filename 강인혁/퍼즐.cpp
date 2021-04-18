#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class State
{
    public:
    
    int arr[3][3];
    	
    vector<State> getAdjacent() const;
    // map에 넣기 위함 
    bool operator < (const State& rhs) const{
    	for(int i=0; i<3; i++){
    		for(int j =0; j<3; j++){
    			if(arr[i][j] == rhs.arr[i][j]) continue;
    			if(arr[i][j] < rhs.arr[i][j]) return true;
    			else return false;
			}
		}
		return false;
	}
    
    // 종료상태 비교를 위함 
    bool operator == (const State& rhs) const{
    	bool ok = true;
    	for(int i=0; i<3; i++){
    		for(int j=0; j<3; j++){
    			if(arr[i][j] != rhs.arr [i][j]){
    				ok = false;
    				break;
				}
			}
		}
		return ok;
	}
};
 
typedef map<State, int> StateMap;
 
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};


 
int bfs(State start, State finish){
	queue<State> q;
	StateMap m;
	q.push(start);
	m[start] = 0;
	if(start == finish) return 0;
	
	while(!q.empty()){
		State here = q.front();
		int dist = m[here];
		q.pop();
		
		for(int y=0; y< 3; y++)
			for(int x = 0; x < 3; x++)
				if(here.arr[y][x] == 0)
					for(int i=0; i<4; i++){
						int nextY = y + dy[i];
						int nextX = x + dx[i];
						if(nextY < 0 || nextY >= 3 || nextX < 0 || nextX >= 3) continue;
						State next;
						for(int i=0; i<3; i++){
							for(int j =0; j<3; j++){
								next.arr[i][j] = here.arr[i][j];
							}
						}
						swap(next.arr[y][x], next.arr[nextY][nextX]);
						if(m.count(next) == 0){
							if(next == finish) return dist + 1;
							q.push(next);
							m[next] = dist + 1;
							
						}
					}
	}
	
	return -1;
}
 
int main(int argc, char** argv) {
	
	State start;
	State finish;
	for(int i=0; i< 3; i++)
		for(int j=0; j<3; j++)
			cin >> start.arr[i][j];
		
	for(int i=0; i<3; i++)
		for(int j =0; j<3; j++){
			finish.arr[i][j] = i * 3 + j + 1;
			if(i == 2 && j == 2) finish.arr[i][j] = 0;
		}

	
	int ans = bfs(start, finish);
	cout << ans << endl;

	return 0;
}
