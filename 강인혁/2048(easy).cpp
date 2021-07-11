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

class State{
    public :
        vector<vector<int>> block;
        vector<State> getAdjacent() const;
        bool operator < (const State& rhs) const;
        bool operator == (const State& rhs) const;
        int getMax();
};

typedef map<State,int> StateMap;

int n;

int func(const vector<vector<int>>& startBlock){
    State startState;
    startState.block = startBlock;

    StateMap m;
    m[startState] = 0;
    queue<State> q;
    q.push(startState);

    int ret = startState.getMax();
    while(!q.empty()){
        State here = q.front();
        q.pop();
        int cost = m[here];
        if(cost >= 5) continue;
        
        vector<State> adjacent = here.getAdjacent();
        
        for(int i=0; i< adjacent.size(); i++){
            State next = adjacent[i];
            if(m.count(next) == 0){
                q.push(next);
                m[next] = cost + 1;
                ret = max(ret, next.getMax());
            }
        }
    }

    return ret;
}

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

bool taken[22][22];

vector<State> State::getAdjacent() const{
    vector<State> ret;
    // 동서남북으로 밀어본 네가지 경우를 반환
    // 동 서
    
    for(int i=0; i<2; i++){
        memset(taken, false, sizeof(taken));
        vector<vector<int>> nextBlock = block;
        int dirY = dy[i], dirX = dx[i];
        for(int y =0; y<n; y++){
            if(i == 0){
                for(int x = n-1; x>=0; x--){
                    if(nextBlock[y][x] == 0) continue;
                    int curBlock = nextBlock[y][x];
                    if(x == n-1) continue;
                    else{
                        int nextY = y, nextX = x;
                        // 숫자나 벽을 만날 때 까지 움직임
                        while(nextBlock[nextY + dirY][nextX + dirX] == 0 && nextX + dirX < n){
                            nextY += dirY, nextX += dirX;
                        }
                        // 벽을 만난 경우
                        if(nextX + dirX >= n){
                            if(nextY == y && nextX == x) continue;
                            nextBlock[nextY][nextX] = nextBlock[y][x];
                            nextBlock[y][x] = 0;
                            continue;
                        }
                        // 자기랑 같은 숫자를 만난 경우
                        if(nextBlock[nextY + dirY][nextX + dirX] == nextBlock[y][x] && !taken[nextY + dirY][nextX + dirX]){
                            nextBlock[nextY + dirY][nextX + dirX] *= 2;
                            taken[nextY + dirY][nextX + dirX] = true;
                            nextBlock[y][x] = 0;
                        }
                        else{
                            if(nextY == y && nextX == x) continue;
                            nextBlock[nextY][nextX] = nextBlock[y][x];
                            nextBlock[y][x] = 0;
                        }
                    }
                }
            }
            else if(i == 1){
                for(int x = 0; x<n; x++){
                    if(nextBlock[y][x] == 0) continue;
                    int curBlock = nextBlock[y][x];
                    if(x == 0) continue;
                    else{
                        int nextY = y, nextX = x;
                        // 숫자나 벽을 만날 때 까지 움직임
                        while(nextBlock[nextY + dirY][nextX + dirX] == 0 && nextX + dirX >=0){
                            nextY += dirY, nextX += dirX;
                        }
                        // 벽을 만난 경우
                        if(nextX + dirX < 0){
                            if(nextY == y && nextX == x) continue;
                            nextBlock[nextY][nextX] = nextBlock[y][x];
                            nextBlock[y][x] = 0;
                            continue;
                        }
                        
                        // 자기랑 같은 숫자를 만난 경우
                        if(nextBlock[nextY + dirY][nextX + dirX] == nextBlock[y][x] && !taken[nextY + dirY][nextX + dirX]){
                            nextBlock[nextY + dirY][nextX + dirX] *= 2;
                            taken[nextY + dirY][nextX + dirX] = true;
                            nextBlock[y][x] = 0;
                        }
                        else{
                            if(nextY == y && nextX == x) continue;
                            nextBlock[nextY][nextX] = nextBlock[y][x];
                            nextBlock[y][x] = 0;
                        }
                    }
                }
            }
        }

        State nextState;
        nextState.block = nextBlock;
        ret.push_back(nextState);
    }
    
    // 남 북
    for(int i=2; i<4; i++){
        memset(taken, false, sizeof(taken));
        vector<vector<int>> nextBlock = block;
        int dirY = dy[i], dirX = dx[i];
        for(int x =0; x<n; x++){
            if(i == 2){
                for(int y = n-1; y>=0; y--){
                    if(nextBlock[y][x] == 0) continue;
                    int curBlock = nextBlock[y][x];
                    if(y == n-1) continue;
                    else{
                        int nextY = y, nextX = x;
                        // 숫자나 벽을 만날 때 까지 움직임
                        while(nextY + dirY < n && nextBlock[nextY + dirY][nextX + dirX] == 0){
                            nextY += dirY, nextX += dirX;
                        }
                        // 벽을 만난 경우
                        if(nextY + dirY >= n){
                            if(nextY == y && nextX == x) continue;
                            nextBlock[nextY][nextX] = nextBlock[y][x];
                            nextBlock[y][x] = 0;
                            continue;
                        }

                        // 자기랑 같은 숫자를 만난 경우
                        if(nextBlock[nextY + dirY][nextX + dirX] == nextBlock[y][x] && !taken[nextY + dirY][nextX + dirX]){
                            nextBlock[nextY + dirY][nextX + dirX] *= 2;
                            taken[nextY + dirY][nextX + dirX] = true;
                            nextBlock[y][x] = 0;
                        }
                        else{
                            if(nextY == y && nextX == x) continue;
                            nextBlock[nextY][nextX] = nextBlock[y][x];
                            nextBlock[y][x] = 0;
                        }
                    }
                }
            }
            else if(i == 3){
                for(int y = 0; y<n; y++){
                    if(nextBlock[y][x] == 0) continue;
                    int curBlock = nextBlock[y][x];
                    if(y == 0) continue;
                    else{
                        int nextY = y, nextX = x;
                        // 숫자나 벽을 만날 때 까지 움직임
                        while(nextY + dirY >= 0 && nextBlock[nextY + dirY][nextX + dirX] == 0){
                            nextY += dirY, nextX += dirX;
                        }
                        
                        // 벽을 만난 경우
                        if(nextY + dirY < 0){
                            if(nextY == y && nextX == x) continue;
                            nextBlock[nextY][nextX] = nextBlock[y][x];
                            nextBlock[y][x] = 0;
                            continue;
                        }

                        // 자기랑 같은 숫자를 만난 경우
                        if(nextBlock[nextY + dirY][nextX + dirX] == nextBlock[y][x] && !taken[nextY + dirY][nextX + dirX]){
                            nextBlock[nextY + dirY][nextX + dirX] *= 2;
                            taken[nextY + dirY][nextX + dirX] = true;
                            nextBlock[y][x] = 0;
                        }
                        else{
                            if(nextY == y && nextX == x) continue;
                            nextBlock[nextY][nextX] = nextBlock[y][x];
                            nextBlock[y][x] = 0;
                        }
                    }
                }
            }
        }
        State nextState;
        nextState.block = nextBlock;
        ret.push_back(nextState);
    }
    return ret;
}

bool State::operator<(const State& rhs) const{
    /*
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(block[i][j] > rhs.block[i][j]) return true;
            else if(block[i][j] == rhs.block[i][j]) continue;;
        }
    }
    return false;
    */
   return block < rhs.block;
}

bool State::operator ==(const State& rhs) const{
    return block == rhs.block;
}

int State::getMax(){
    int ret = -1;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ret = max(ret, block[i][j]);
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    vector<vector<int>> startBlock(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> startBlock[i][j];
        }
    }

    int ret = func(startBlock);
    cout << ret << endl;

    return 0;
}
