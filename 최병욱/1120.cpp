#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a = "";
string b = "";

int getDiff(int start)
{
	int diff = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[start + i]) diff++;
	}

	return diff;
}

int main()
{
	cin >> a >> b;

	int diff = b.size() - a.size();

	int answer = 100;
	for (int i = 0; i < diff + 1; i++)
	{
		answer = min(answer, getDiff(i));
	}

	cout << answer << endl;

	return 0;
}