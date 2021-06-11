#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define endl '\n'
typedef long long ll;

using namespace std;

const int INF = 0x7FFFFFFF;

int n, s;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<ll> arr(n);
    for(int i= 0; i<n; i++) cin >> arr[i];

    vector<bool> visited(n, false);
    int start =0, end = 0;

    ll ret = 0;
    while(start <= n){
        if(!visited[arr[end]] && end < n){
            visited[arr[end]] = true;
            end++;
        }
        else{
            visited[arr[start]] = false;

            ret += (end - start);

            start++;

        }
    }

    cout << ret << endl;
    return 0;
}


