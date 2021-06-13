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

const int MAXN = 11111;
// 1이면 소수... 0 이면 합성수
bool prime[MAXN];


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b); 
}

int lcd(int a, int b){
    return a * b / gcd(a,b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int>A(n), B(k);
    // 예각만 취급
    for(int i=0; i<n; i++){
        cin >> A[i];
        A[i] = gcd(A[i], 360);
    }
    for(int i=0; i<k; i++){
        cin >> B[i];
    }

    int g=  A[0];
    for(int i=0; i<n; i++) g = gcd(g, A[i]);

    for(int i=0; i<k; i++){
        if(B[i] % g == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    

    return 0;
}




