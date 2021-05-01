#include <iostream>
#include <vector>
using namespace std;

int dp[40] = {0};

int fib(int n)
{
	if (n == 0 || n == 1) return n;

	if (dp[n] != 0) return dp[n];

	return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
	int t = 0;
	cin >> t;

	while(t--)
	{
		int num = 0;
		cin >> num;
		fib(num);

		if (num == 0)
			cout << "1 0" << endl;
		else
			cout << fib(num - 1) << ' ' << fib(num) << endl;
	}

	return 0;
}