#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L = 0;
int C = 0;
vector<char> alphabets;

bool satisfy(const vector<char>& word)
{
	int vowels = 0;
	int cons = 0;

	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == 'a' ||word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
			vowels++;
		else
			cons++;
	}

	return vowels >= 1 && cons >= 2;
}

void solve(int idx, vector<char>& word)
{
	if (word.size() == L)
	{
		// 조건에 부합하지 않는 암호문이라면 출력하지않음.
		if (!satisfy(word)) return;

		for (int i = 0; i < word.size(); i++)
		{
			cout << word[i];
		}
		cout << endl;
		return;
	}

	if (idx >= alphabets.size()) return;

	for (int i = idx; i < alphabets.size(); i++)
	{
		word.push_back(alphabets[i]);
		solve(i + 1, word);
		word.pop_back();
	}
}

int main()
{
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;
		alphabets.push_back(c);
	}

	sort(alphabets.begin(), alphabets.end());

	vector<char> word;
	solve(0, word);

	return 0;
}