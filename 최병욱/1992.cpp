#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N = 0;
vector<int> matrix;

void solve(int y, int x, int size)
{
	int satisfy = true;
	int check = matrix[y * N + x];
	for (int dy = 0; dy < size; dy++)
	{
		for (int dx = 0; dx < size; dx++)
		{
			if (check != matrix[(y + dy) * N + x + dx])
			{
				satisfy = false;
				break;
			}
		}
	}

	if (satisfy)
	{
		cout << check;
	}
	else
	{
		cout << '(';

		int half = size / 2;
		solve(y, x, half);
		solve(y, x + half, half);
		solve(y + half, x, half);
		solve(y +half, x + half, half);

		cout << ')';
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			matrix.push_back(str[j] - '0');
		}
	}


	solve(0, 0, N);

	return 0;
}