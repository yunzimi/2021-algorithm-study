#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
int answer = 10000001;
int dp[1000][3];
vector<vector<int>> colors;

int main()
{
	cin >> N;

	for (int i = 0; i < 3; i++)
	{
		vector<int> color;
		colors.push_back(color);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int cost = 0;
			cin >> cost;
			colors[j].push_back(cost);
		}
	}

	dp[0][0] = colors[0][0];
	dp[0][1] = colors[1][0];
	dp[0][2] = colors[2][0];


	for (int i = 1; i < N; i++)
	{
		dp[i][0] = min(dp[i -1][1], dp[i - 1][2]) + colors[0][i];
		dp[i][1] = min(dp[i -1][0], dp[i - 1][2]) + colors[1][i];
		dp[i][2] = min(dp[i -1][0], dp[i - 1][1]) + colors[2][i];
	}


	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2])) << endl;

	return 0;
}