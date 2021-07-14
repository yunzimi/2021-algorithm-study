/*  Created by Dandalf on 2021. 7. 14.
 *  problem:  boj.kr/2027,
 *  tier:     G1                       */

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, k;
ll a, b, c;
vector<ll> arr, tree;

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = arr[start];  // leaf node
  int mid = (start + end) / 2;
  return tree[node] =
             init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll sum(int node, int start, int end, int left, int right) {
  if (right < start || left > end) return 0;
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) +
         sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, ll diff) {
  if (index < start || end < index) return;
  tree[node] += diff;
  if (start == end) return;
  int mid = (start + end) / 2;
  update(node * 2, start, mid, index, diff);
  update(node * 2 + 1, mid + 1, end, index, diff);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> k;
  int h = (int)ceil(log2(n));
  ll size = 1 << (h + 1);

  arr.resize(n);
  tree.resize(size);  // 2^k fixed

  for (auto &e : arr) cin >> e;
  init(1, 0, n - 1);

  for (int i = 0; i < m + k; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      ll diff = c - arr[b - 1];
      arr[b - 1] = c;
      update(1, 0, n - 1, b - 1, diff);
    } else
      cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
  }
  return 0;
}