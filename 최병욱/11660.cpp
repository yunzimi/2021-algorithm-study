#include <iostream>
using namespace std;

int dp[1025][1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m = 0;
	cin >> n >> m;

	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= n; y++)
		{
			int val = 0;
			cin >> val;
			dp[x][y] = dp[x - 1][y] + dp[x][y - 1] + val - dp[x - 1][y - 1];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 -1][y2] - dp[x2][y1 -1] + dp[x1 -1][y1 - 1] << '\n';
	}

	return 0;
}