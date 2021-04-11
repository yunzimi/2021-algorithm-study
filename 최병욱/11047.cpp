#include <iostream>
#include <vector>
using namespace std;

int N = 0;
int K = 0;
vector<int> values;

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int val = 0;
		cin >> val;
		values.push_back(val);
	}

	int target = K;
	int ans = 0;
	for (int i = values.size() - 1; i >= 0; i--)
	{
		if (target == 0) break;

		if (target < values[i]) continue;

		ans += target / values[i];
		target = target % values[i];
	}

	cout << ans << endl;

	return 0;
}