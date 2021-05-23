#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;

	while (t--)
	{
		string p;
		cin >> p;

		int n;
		cin >> n;

		string strArr;
		cin >> strArr;

		vector<int> nums;
		int last = 1;
		while(n != 0)
		{
			string numStr = "";
			for (int i = last; i < strArr.size(); i++)
			{
				if (n == 1 && strArr[i] == ']')
					break;
				else if (strArr[i] == ',')
				{
					last = i + 1;
					break;
				}

				numStr += strArr[i];
			}

			nums.push_back(stoi(numStr));
			n--;
		}

		bool isReverse = false;
		int front = 0;
		int end = nums.size() - 1;
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
				isReverse = !isReverse;
			else
			{
				if (isReverse)
					end--;
				else
					front++;
			}
		}

		if (front > end && end < front)
		{
			if (abs(front - end) == 1)
				cout << "[]" << endl;
			else
				cout << "error" << endl;
		}
		else
		{
			cout << '[';
			if (isReverse)
			{
				for (int i = end; i >= front; i--)
				{
					cout << nums[i];
					if (i != front)
						cout << ',';
				}
			}
			else
			{
				for (int i = front; i <= end; i++)
				{
					cout << nums[i];
					if (i != end)
						cout << ',';
				}
			}
			cout << ']' << endl;
		}
	}

	return 0;
}