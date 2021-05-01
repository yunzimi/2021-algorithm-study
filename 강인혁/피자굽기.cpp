#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>

typedef long long ll;

using namespace std;

const int INF = 987654321;

int D, N;
vector<int> oven, dow;

// idx의 피자가 depth 지름을 통과할 수 있는가 
bool decision(int depth, int idx){
	return oven[depth] >= dow[idx];
}

int main(int argc, char** argv) {
	
	cin >> D >> N;
	
	oven = vector<int>(D+1);
	oven[0] = INF;
	for(int i=1; i<=D; i++){
		cin >> oven[i];
	}
	
	int max = oven[1];
	
	for(int i=1; i<= D; i++){
		if(max < oven[i]) oven[i] = max;
		else{
			max = oven[i];
		}
	}
	
	dow = vector<int>(N+1);
	for(int i=1; i<=N; i++){
		cin >> dow[i];
	}
	
	int ans = D+1;
	for(int i = 1; i <= N; i++){
		if(ans == 0) break;
		int lo = 0; 
		int hi= ans;
		for(int iter = 0; iter < 100; iter++){
			int mid = (lo + hi)/2; 
			// decision(lo) && !decision(hi)
			if(decision(mid, i)) lo = mid;
			else hi = mid;
		}
		
		ans = lo;
		
		//cout << ans <<" " << i << endl;
	}

	
	cout << ans << endl;
	
	
	return 0;
}
