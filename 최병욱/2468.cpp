#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N = 0;
int area[101][101];
bool visit[101][101];

int solve(int h)
{
	int ret = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			// 물에 잠겼거나 이미 방문한곳은 패스
			if (area[y][x] <= h || visit[y][x])
				continue;

			ret++;

			queue<pair<int, int>> q;
			q.push(make_pair(y, x));

			while(!q.empty())
			{
				int refY = q.front().first;
				int refX = q.front().second;
				q.pop();

				int dx[] = {1, -1, 0, 0};
				int dy[] = {0, 0, 1, -1};
				for (int i = 0; i < 4; i++)
				{
					int toY = refY + dy[i];
					int toX = refX + dx[i];
					if (toY >= 0 && toY < N && toX >= 0 && toX < N &&
						!visit[toY][toX] && area[toY][toX] > h)
					{
						visit[toY][toX] = true;
						q.push(make_pair(toY, toX));
					}
				}
			}
		}
	}

	return ret;
}

void visitReset()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			visit[y][x] = false;
		}
	}
}

int main()
{
	cin >> N;

	int biggest = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> area[i][j];
			biggest = max(biggest, area[i][j]);
		}
	}

	int answer = 0;
	for (int i = 0; i < biggest; i++)
	{
		visitReset();
		answer = max(answer, solve(i));
	}

	cout << answer << endl;

	return 0;
}