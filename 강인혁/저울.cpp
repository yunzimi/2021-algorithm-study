#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

typedef long long ll;

using namespace std;

const int INF = 987654321;

int main(int argc, char** argv) {
	int n;
	cin >> n;
	
	
	vector<int> plumbs(n);
	
	for(int i=0; i<n; i++){
		cin >> plumbs[i];
	}
	
	sort(plumbs.begin(), plumbs.end());

	int lastContinuous = 0;
	
	int ans = 1;
	for(int i=0; i< n; i++){
		if(lastContinuous + 1 < plumbs[i]){
			ans = lastContinuous + 1;
			break;
		}
		if(i == n-1){
			ans = lastContinuous + plumbs[i] + 1;
			break;
		}
		
		lastContinuous += plumbs[i];
	}
	
	cout << ans;
	
	return 0;
}
