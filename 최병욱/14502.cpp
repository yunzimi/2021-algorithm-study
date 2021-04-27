#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N = 0;
int M = 0;
int answer = -1;
vector<vector<int>> map;

vector<vector<int>> spread()
{
	vector<vector<int>> ret = map; // copy map

	// find virus elem
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ret[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	// spreading virus
	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N)
			{
				if (ret[ny][nx] == 0)
				{
					ret[ny][nx] = 2;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

	return ret;
}

void solve(int cnt)
{
	if (cnt == 3)
	{
		vector<vector<int>> copyMap = spread();

		// count safe area
		int comp = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (copyMap[y][x] == 0)
					comp++;
			}
		}

		answer = max(answer, comp);
	}
	else
	{
		// build wall
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (map[y][x] == 0)
				{
					map[y][x] = 1;
					solve(cnt + 1);
					map[y][x] = 0;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	map = vector<vector<int>>(N, vector<int>(M, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> map[y][x];
		}
	}

	solve(0);

	cout << answer << endl;

	return 0;
}