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

const int MAXN = 4444444;
// 1이면 소수... 0 이면 합성수
bool prime[MAXN];

int n;

int getG(int a, int b){
    if(b == 0) return a;

    return getG(b, a%b);
}

int getL(int a, int b){
    return (a * b) / getG(a,b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(prime, true, sizeof(prime));
    for(int i=2; i * i < MAXN; i++){
        if(!prime[i]) continue;
        for(int j = i *i ; j < MAXN; j+=i){
            prime[j] = false;
        }
    }

    cin >> n;
    // 소수를 저장
    vector<int>primes;
    int dst =0;
    for(int i=2; i<= n; i++){
        if(prime[i]){
            primes.push_back(i);
            dst++;
        }
    }

    int ans =0;
    int curSum = 0;
    
    for(int start = 0, end = -1; start < dst; start++){
        while(curSum < n && end < dst){
            curSum += primes[++end];
        }
        if(curSum == n) ans++;

        curSum -= primes[start];
    }


    cout << ans << endl;

    return 0;
}




