#include<iostream>

using namespace std;

int func(int n);

int d[1000000];

int main()
{	
	int n;
	cin >> n;
	cout << func(n);
}

int func(int n)
{
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];
	d[n] = func(n - 1) + 1;
	if (n % 3 == 0)
	{
		int tmp = func(n / 3) + 1;
		if (d[n] > tmp)
		{
			d[n] = tmp;
		}
	}
	if (n % 2 == 0)
	{
		int tmp = func(n / 2) + 1;
		if (d[n] > tmp)
		{
			d[n] = tmp;
		}
	}
	return d[n];
}