#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int check[2000000];
int selec[46];
vector<int> input;
vector<int> V;
int n, m;
int l;
int ans = 0;

void dfs(int idx, int cnt)
{
    if (cnt == l) {
        int sum = 0;
        for (int i = 0; i < V.size(); i++) {
            sum += V[i];
        }
        check[sum] = 1;
        return;
    }

    for (int i = idx; i < n; i++) {
        if (selec[i] == true)continue;
        selec[i] = true;
        V.push_back(input[i]);
        dfs(i + 1, cnt + 1);
        V.pop_back();
        selec[i] = false;
    }

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        input.push_back(x);
    }
    sort(input.begin(), input.end());
    for (int i = 1; i <= n; i++) {
        l = i;
        dfs(0, 0);
    }
    for (int i = 1; i<= 2000000; i++) {
        ans++;
        if(!check[i]) break;
    }
    cout << ans;
}
