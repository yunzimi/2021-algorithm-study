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

int N, M, K;

int board[21][21];

int dice[6];

// 동 서 북 남
const int dy[4] = {0,0,-1,1};
const int dx[4] = {1,-1,0,0};

const int top[6] = {5,4,3,2,1,0};

int main(){
    int startY, startX;

    cin >> N >> M >> startY >> startX >> K;
    for(int i =0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    vector<int> cmd(K);

    for(int i=0; i<K; i++){
        cin >> cmd[i];
        cmd[i]--;
    }

    int curY = startY, curX = startX;

    int curBottom =0, curDown = 4, curRight = 2;
    for(int i=0; i<K; i++){
        int curCmd = cmd[i];
        int nextY = curY + dy[curCmd], nextX = curX + dx[curCmd];
        if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
        int nextBottom, nextDown, nextRight;
        switch (curCmd)
        {
        case 0:
            nextBottom = top[curRight];
            nextDown = curDown;
            nextRight = curBottom;
            break;
        case 1:
            nextBottom = curRight;
            nextDown = curDown;
            nextRight = top[curBottom];
            break;
        case 2:
            nextBottom = top[curDown];
            nextDown = curBottom;
            nextRight = curRight;
            break;
        case 3:
            nextBottom = curDown;
            nextDown = top[curBottom];
            nextRight = curRight;
            break;
        }

        curBottom = nextBottom;
        curDown = nextDown;
        curRight = nextRight;

        if(board[nextY][nextX] == 0){
            board[nextY][nextX] = dice[curBottom];
        }
        else{
            dice[curBottom] = board[nextY][nextX];
            board[nextY][nextX] = 0;
        }
        cout << dice[top[curBottom]] << endl;

        curY = nextY, curX = nextX;
    }

    return 0;
}

