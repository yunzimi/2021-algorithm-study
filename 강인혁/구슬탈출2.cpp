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

//const int INF = 0x7FFFFFFF;
const int INF = 99999;
int n, m;

char block[22][22];
int dist[22][22][22][22];
int dirY[4] = {0,0,1,-1};
int dirX[4] = {1,-1,0,0};

int startY, startX;
int blueY, blueX;
int endY, endX;

int bfs(int startY, int startX, int blueY, int blueX){
    int ret = -1;
    queue<pair<pair<pair<int,int>, pair<int,int>>,int>> q;
    q.push({{{startY, startX}, {blueY, blueX}}, 0});
    dist[startY][startX][blueY][blueX] = 0;
    
    while(!q.empty()){
        int curY = q.front().first.first.first, curX = q.front().first.first.second;
        int bY = q.front().first.second.first, bX = q.front().first.second.second;
        int curCost = q.front().second;
        dist[curY][curX][bY][bX] = curCost;
        q.pop();

        if(curCost >= 10) continue;

        //cout << curY << "   " << curX  << "  " << bY << "  "  << bX<< endl;

        if(curY == endY && curX == endX){
            ret = curCost;
            return ret;
        }

        for(int i=0; i<4; i++){
            int dy = dirY[i], dx = dirX[i];
            // 벽을 만날때까지 계속 움직이기
            int nextY = curY, nextX = curX;
            int nextBY = bY, nextBX = bX;

            
            bool finished = false;
            bool Bfinished = false;
            while(1){
                if(block[nextY + dy][nextX + dx] == '#' || ((nextY + dy == nextBY) && (nextX + dx == nextBX))){
                    break;
                }
                if(block[nextY + dy][nextX + dx] == 'O'){
                    finished = true;
                    nextY = 0, nextX = 0;
                    break;
                }
                nextY += dy, nextX += dx;
            }
            while(1){
                if(block[nextBY + dy][nextBX + dx] == '#' || ((nextBY + dy == nextY) && (nextBX + dx == nextX))) break;
                if(block[nextBY + dy][nextBX + dx] == 'O'){
                    Bfinished = true;
                    break;
                }
                nextBY += dy, nextBX += dx;
            }
            if(!finished)
                while(1){
                    if(block[nextY + dy][nextX + dx] == '#' || ((nextY + dy == nextBY) && (nextX + dx == nextBX))){
                    break;
                }
                    if(block[nextY + dy][nextX + dx] == 'O'){
                        finished = true;
                        break;
                    }
                    nextY += dy, nextX += dx;
                }
            if(!Bfinished)
                while(1){
                    if(block[nextBY + dy][nextBX + dx] == '#' || ((nextBY + dy == nextY) && (nextBX + dx == nextX))) break;
                    if(block[nextBY + dy][nextBX + dx] == 'O'){
                        Bfinished = true;
                        break;
                    }
                    nextBY += dy, nextBX += dx;
                }

            if(Bfinished) continue;
            if(finished){
                return curCost + 1;
            }
            
            if(nextY != curY || nextX != curX || nextBY != bY || nextBX != bX)
                if(dist[nextY][nextX][nextBY][nextBX] == -1)
                    q.push({{{nextY, nextX}, {nextBY, nextBX}}, curCost+1});
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        for(int j=0; j<m; j++){
            block[i][j] = temp[j];
            if(block[i][j] == 'O') endY = i, endX = j;
            if(block[i][j] == 'R') startY = i, startX = j;
            if(block[i][j] == 'B') blueY = i, blueX = j;
        }
    }

    memset(dist,-1,sizeof(dist));
    int ret = bfs(startY, startX, blueY, blueX);
    cout << ret << endl;



    return 0;
}
