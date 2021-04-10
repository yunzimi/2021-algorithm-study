#include <bits/stdc++.h>

using namespace std;

int selec[46];
char input[20][20];
int check[20][20];
vector<char> V;
int n, m;
int l;
int ans = 0;
int ax[] = { 0,0,-1,1 };
int ay[] = { -1,1,0,0 };

void dfs(int x, int y, int cnt)
{
	ans = ans < cnt ? cnt : ans;
	for (int i = 0; i < 4; i++) {
		int dx = x + ax[i];
		int dy = y + ay[i];
		if (check[dx][dy] == true) continue;
		auto it = find(V.begin(), V.end(), input[dx][dy]);
		if (it == V.end()) {
			if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
			check[dx][dy] = true;
			V.push_back(input[dx][dy]);
			dfs(dx, dy, cnt + 1);
			V.pop_back();
			check[dx][dy] = false;
		}
	}

}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
		}
	}

	check[0][0] = true;
	V.push_back(input[0][0]);
	dfs(0, 0, 1);

	cout << ans;
}