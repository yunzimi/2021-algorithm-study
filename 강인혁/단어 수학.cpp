#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

typedef long long ll;

using namespace std;

const int INF = 987654321;

int main(int argc, char** argv) {
	int n;
	cin >> n;
	
	vector<int> sets(26, 0);
	
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int i=0; i< s.size(); i++){
			sets[s[i] - 'A'] += pow(10, s.size() - i -1);
		}
	}
	
	sort(sets.begin(), sets.end(), greater<int>());
	
	int ans =0;
	
	int curN = 9;
	for(int i =0; i<26; i++){
		ans += sets[i] * curN;
		curN--;
	}
	
	cout << ans << endl;
	
	return 0;
}
