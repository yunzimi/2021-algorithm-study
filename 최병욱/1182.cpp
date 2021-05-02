#include <iostream>
#include <vector>
using namespace std;

int N = 0;
int S = 0;
int answer = 0;
vector<int> numbers;

void solve(int idx, int acc)
{
	if (acc == S && idx != 0){
		answer++;
	}

	if (idx == N) return;

	for (int i = idx; i < N; i++)
	{
		solve(i + 1, acc + numbers[i]);
	}
}

int main()
{
	cin >> N >> S;

	for (int i =0 ; i < N; i++)
	{
		int num = 0;
		cin >> num;
		numbers.push_back(num);
	}

	solve(0, 0);
	cout << answer << endl;

	return 0;
}