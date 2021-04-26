#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int maxResult = -1000000001;
int minResult= 1000000001;
vector<int> operands;
vector<int> operators;

void ans(int result, int idx)
{
	if (idx == N)
	{
		maxResult = max(result, maxResult);
		minResult = min(result, minResult);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (operators[i] <= 0) continue;

			int cache = operators[i]--;

			int newResult = 0;
			if (i == 0)
				newResult = result + operands[idx];
			else if (i == 1)
				newResult = result - operands[idx];
			else if (i == 2)
				newResult = result * operands[idx];
			else
				newResult = result / operands[idx];

			ans(newResult, idx + 1);

			operators[i] = cache;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		operands.push_back(num);
	}

	for (int i = 0; i < 4; i++)
	{
		int num = 0;
		cin >> num;
		operators.push_back(num);
	}

	ans(operands[0], 1);

	cout << maxResult << endl;
	cout << minResult << endl;

	return 0;
}