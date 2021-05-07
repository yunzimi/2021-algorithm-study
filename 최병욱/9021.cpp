#include <iostream>
#include <string>
using namespace std;

void solve(string str)
{
	int left = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			left++;
		}
		else
		{
			if (left <= 0)
			{
				cout << "NO" << endl;
				return;
			}
			else
				left--;
 		}
	}

	if (left == 0)
		cout << "YES" << endl;
	else
		cout <<"NO" << endl;
}


int main()
{

	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string str = "";
		cin >> str;
		solve(str);
	}

	return 0;
}