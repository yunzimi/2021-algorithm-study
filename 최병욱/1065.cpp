#include <iostream>
#include <vector>
using namespace std;

bool isHansu(int num)
{
	// 100보다 작으면 true
	if (num < 100) return true;

	int d = ((num / 10) % 10) - (num % 10);

	num /= 10;
	while (num / 10 != 0)
	{
		int last = num % 10;
		int comp = ((num / 10) % 10);
		if (comp != last + d)
			return false;

		num /= 10;
	}

	return true;
}

int main()
{
	int n = 0;
	cin >> n;

	int ans = 0;
	for (int i = 1; i <=n; i++){
		if (isHansu(i)) ans++;
	}

	cout << ans << endl;

	return 0;
}