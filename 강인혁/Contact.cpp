#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// pattern 은 
// (10 0+ 1+  | 01 )+ 
// 문자열 길이가 [1,200]
// x+ 는 이제 xx, xxx, ..로 치환
// x|y 는  x, y, xy, yx ...

int cache[201];

// s[idx, n-1]가 true가 될 수 있나 참이면 1, 거짓이면 0 
int func(int idx, int n, const string& s){
	if(idx > n) return 0;
	if(idx == n) return 1;
	
	int &ret = cache[idx];
	if(ret == 1) return ret;
	
	ret = 0;
	
	// 01이 있는 경우 
	if(s[idx] == '0' && s[idx + 1] == '1') ret |= func(idx + 2, n, s);
	
	// 100..01..1의 경우
	if(s[idx] == '1' && s[idx + 1] == '0'){
		if(s[idx + 2] == '0'){
			int nextIdx = idx+2;
			while(s[nextIdx] == '0'){
				nextIdx++;
			}	
			while(s[nextIdx] == '1'){
				nextIdx++;
				ret |= func(nextIdx, n, s);
			}
		}
	}
	
	return ret;
}

bool pattern(const string& s){
	memset(cache,0,sizeof(cache));
	int n = s.size();
	
	if(func(0, n, s)) return true;
	return false;
}


int main(int argc, char** argv) {
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		if(pattern(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}
