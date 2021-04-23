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

int n, m;
vector<ll> jewelry;

// piece개로 나눠서 n명 이하에게 줄 수 있는가  
bool decision(ll piece){
	ll cnt =0;
	for(int i=0; i<m; i++){
		cnt += (jewelry[i] / piece);
		if(jewelry[i] % piece) cnt++; // 초과한 경우 하나 더 셈 
	}
	
	return cnt <= n;
}

int main(int argc, char** argv) {
	
	cin >> n >> m;
	
	jewelry = vector<ll>(m);
	
	ll maxJ = 0;
	for(int i=0; i<m; i++){
		cin >> jewelry[i];
		maxJ = max<ll>(maxJ, jewelry[i]);
	}
	
	ll ans = 1;
	ll lo = 0, hi = maxJ;
	while(lo + 1 < hi){
		ll mid = (lo + hi) /2;
		// mid가 보석 주는 개수
		// !decision(lo) && decision(hi)
		if(decision(mid)) {
			hi = mid;
		}
		else{
			lo = mid;
		}
			
	}
	


	cout << hi << endl;
	
	return 0;
}
