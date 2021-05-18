#include <iostream>
#include <vector>
using namespace std;

int N = 0;
vector<int> tree[100002];
int parent[100002];

void dfs(int node)
{
	for (int i = 0; i < tree[node].size(); i++)
	{
		int c = tree[node][i];
		if (parent[c] < 0)
		{
			parent[c] = node;
			dfs(c);
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		parent[i + 2] = -1;

		int n1, n2 = 0;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	dfs(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}