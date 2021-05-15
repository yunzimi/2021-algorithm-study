#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
int K = 0;
vector<pair<int, int>> things;
int dp[101][100001];

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int w, v = 0;
		cin >> w >> v;
		things.push_back(make_pair(w, v));
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			auto item = things[i - 1];
			int w = item.first;
			int v = item.second;
			if (w > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(v + dp[i - 1][j - w], dp[i - 1][j]);
			}
		}
	}

	cout << dp[N][K] << endl;

	return 0;
}