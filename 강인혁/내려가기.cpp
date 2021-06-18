#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<limits>
#include<cstring>
#include <cmath>

typedef long long ll;
#define endl '\n'

using namespace std;

const int INF = 9876541;

int n, k;

int cache[2][3], cache2[2][3];
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    cin >> n;

    for(int i=0; i<3; i++){
        cin >> cache[1][i];
        cache2[1][i] = cache[1][i];
    }

    for(int i=1; i<=n-1; i++){
        cin >> cache[0][0] >> cache[0][1] >> cache[0][2];
        cache2[0][0] = cache[0][0];
        cache2[0][1] = cache[0][1];
        cache2[0][2] = cache[0][2];

        cache[1][0] = max(cache[1][0], cache[1][1]);
        cache[1][2] = max(cache[1][1], cache[1][2]);
        cache[1][1] = max(cache[1][0], cache[1][2]);

        cache[1][0] += cache[0][0];
        cache[1][1] += cache[0][1];
        cache[1][2] += cache[0][2];

        cache2[1][0] = min(cache2[1][0], cache2[1][1]);
        cache2[1][2] = min(cache2[1][1], cache2[1][2]);
        cache2[1][1] = min(cache2[1][0], cache2[1][2]);

        cache2[1][0] += cache2[0][0];
        cache2[1][1] += cache2[0][1];
        cache2[1][2] += cache2[0][2];
    }

    cout << max(cache[1][0], max(cache[1][1], cache[1][2])) << " " << min(cache2[1][0], min(cache2[1][1], cache2[1][2]));
}


