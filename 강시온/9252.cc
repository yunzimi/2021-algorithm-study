#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int ans = 0;
	int lcs[1001][1001] = { 0, };
	string a, b;
	cin >> a >> b;
	int as, bs;
	string word = "";
	as = a.length();
	bs = b.length();
	for (int i = 1; i <= as; i++) {
		for (int j = 1; j <= bs; j++) {
			if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			ans = max(ans, lcs[i][j]);
		}
	}
	int x = as;
	int y = bs;
	while (lcs[x][y]) {
		if (lcs[x][y] == lcs[x][y - 1])
			y--;
		else if (lcs[x][y] == lcs[x - 1][y])
			x--;
		else if (lcs[x][y] - 1 == lcs[x - 1][y - 1])
		{
			word = a[x - 1] + word;
			x--;
			y--;
		}
	}
	cout << ans << "\n";
	cout << word;
}
