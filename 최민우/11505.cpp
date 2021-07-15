#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll n, m, k;
ll a, b, c;

vector<ll> arr, tree;

ll init(int node, int start, int end) {
  int mid = (start + end) / 2;
  if (start == end) return tree[node] = arr[start];
  return tree[node] =
             (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) %
             MOD;
}

ll mul(int node, int start, int end, int left, int right) {
  if (right < start || left > end) return 1;
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return (mul(node * 2, start, mid, left, right) *
          mul(node * 2 + 1, mid + 1, end, left, right)) %
         MOD;
}

ll update(int node, int start, int end, int index) {
  int mid = (start + end) / 2;
  if (index < start || end < index) return tree[node];
  if (start <= index && index <= end) {
    if (start == end) return tree[node] = arr[start];
    return tree[node] = (update(node * 2, start, mid, index) *
                         update(node * 2 + 1, mid + 1, end, index)) %
                        MOD;
  } else
    return tree[node];
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  int h = (int)ceil(log2(n));
  int size = 1 << (h + 1);
  arr.resize(n);
  tree.resize(size);

  for (auto &e : arr) cin >> e;
  init(1, 0, n - 1);
  for (int i = 0; i < m + k; ++i) {
    cin >> a >> b >> c;
    if (a == 1) {
      int pre = arr[b - 1];
      arr[b - 1] = c;
      update(1, 0, n - 1, b - 1);
    } else
      cout << mul(1, 0, n - 1, b - 1, c - 1) << '\n';
  }
  return 0;
}