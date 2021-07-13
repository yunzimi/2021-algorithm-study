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

int n, k;
int l;

// 1이면, 0이면 빈공간, -1이면 몸통
int board[111][111];

// 동, 남, 서, 북
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int curDir = 0;
int curSize =1;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int y, x;
        cin >> y >> x;
        board[y][x] = 1;
    }
    int curY = 1, curX = 1;
    board[curY][curX] = 0;
    queue<pair<int,int>> body;
    body.push({curY, curX});

    cin >> l;
    queue<pair<int,int>> q;
    for(int i=0; i< l; i++){
        int t; char dir;
        cin >> t >> dir;
        if(dir == 'L'){
            q.push({t, -1});
        }
        else if(dir == 'D'){
            q.push({t, 1});
        }
    }
    
    int curT = 0;
    while(true){
        // 몸통 옮기기
        while(curSize < body.size()){
            int y = body.front().first, x = body.front().second;
            board[y][x] = 0;
            body.pop();
        }
        // 명령 받기
        if(!q.empty()){
            int t = q.front().first, dir = q.front().second;
            if(curT == t){
                curDir += dir + 4;
                curDir %= 4;
                q.pop();
            }
        }
        // 벽에 부딪힌경우
        int nextY = curY + dy[curDir], nextX = curX + dx[curDir];
        
        if(nextY > n || nextX > n || nextY < 1 || nextX < 1){
            curT++;
            break;
        }
        // 사과 먹은 경우
        if(board[nextY][nextX] == 1){
            curSize++;
            board[nextY][nextX] = 0;
        }
        // 몸통에 박은 경우
        if(board[nextY][nextX] == -1){
            curT++;
            break;
        }

        body.push({nextY, nextX});
        board[nextY][nextX] = -1;
        curY = nextY, curX = nextX;
        curT++;
    }

    cout << curT << endl;

    return 0;
}
