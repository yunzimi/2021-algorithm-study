#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num)
{
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) return false;
	}

	return num > 1;
}

int main()
{
	int n = 0;
	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int val = 0;
		cin >> val;
		if (isPrime(val)) ans++;
	}

	cout << ans << endl;

	return 0;
}