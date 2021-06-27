#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#define endl '\n'
typedef long long ll;

using namespace std;

const int INF = 0x7FFFFFFF;
int n, m;

vector<int> arr;

int sccCounter =0;
int vertexCounter =0;

vector<int> scc;
vector<int> discovered;
vector<int> ans[111];

stack<int> st;

int dfs(int here){
    int ret = discovered[here] = vertexCounter++;
    st.push(here);
    int next = arr[here];
    if(discovered[next] == -1){
        ret = min(ret, dfs(next));
    }
    else if(scc[next] == -1){
        ret = min(ret, discovered[next]);
    }

    if(ret == discovered[here]){
        while(true){
            int t = st.top();
            scc[t] = sccCounter;
            ans[sccCounter].push_back(t);
            st.pop();
            if(t == here) break;
        }
        sccCounter++;
    }

    return ret;
}

vector<int> tarjan(){
    scc = vector<int>(n+1, -1);
    discovered = vector<int>(n+1,-1);

    for(int i=1; i<=n; i++){
        if(discovered[i] == -1) dfs(i);
    }

    return scc;    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    arr = vector<int>(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    tarjan();
    vector<int> ret;
    for(int i=0; i<=sccCounter; i++){
        if(ans[i].size() >= 2){
            for(int j=0; j< ans[i].size(); j++) ret.push_back(ans[i][j]);
        }
    }
    for(int i=1; i<=n; i++){
        if(i == arr[i]) ret.push_back(i);
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << endl;
    for(int i=0; i< ret.size(); i++) cout << ret[i] << endl;
    return 0;
}
