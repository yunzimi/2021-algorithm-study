#include <iostream>
#include <algorithm>
using namespace std;

int M = 0;
int N = 0;
int map[500][500];
int dp[500][500];

int solve(int y, int x)
{
	if (y == M - 1 && x == N - 1)
	{
		return 1;
	}
	else if (dp[y][x] == -1)
	{
		dp[y][x] = 0;

		int dy[] = {-1, 1, 0, 0};
		int dx[] = {0, 0, -1, 1};
		for (int i = 0; i < 4; i++)
		{
			int toY = y + dy[i];
			int toX = x + dx[i];

			if (toY < 0 || toY >= M || toX < 0 || toX >= N)
				continue;

			if (map[toY][toX] >= map[y][x])
				continue;

			dp[y][x] += solve(toY, toX);
		}
	}

	return dp[y][x];
}

int main()
{
	cin >> M >> N;

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			dp[y][x] = -1;
			cin >> map[y][x];
		}
	}

	cout << solve(0, 0) << endl;

	return 0;
}