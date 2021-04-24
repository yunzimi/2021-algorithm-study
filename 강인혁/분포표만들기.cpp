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

int m;
vector<double> a, b;

// [0, B[mid])에 A[cur]가 있는가 
bool decision(int mid, int cur){
	double bV = b[mid];
	double aV = a[cur];
	return aV < bV;
}

int main(int argc, char** argv) {
	
	cin >> m;
		
	b = vector<double>(m);
	
	for(int i=0; i<m; i++){
		b[i] = (double)(i + 1) / m;
	}
	
	int n = 0;
	while(1){
		double temp;
		cin >> temp;
		if(cin.eof() == true) break;
		a.push_back(temp);
		n++;
	}
	
	vector<int> ans(m);
	for(int cur=0; cur<n; cur++){
		int lo = -1, hi = m-1;
		// !decision(lo) && decision(hi)
		int mid;
		while(lo + 1 < hi){
			mid = (lo + hi) / 2;
			if(decision(mid, cur)){
				hi = mid;
			}
			else lo = mid;
		}		
		
		ans[hi]++;
	}
	
	for(int i=0; i< ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
