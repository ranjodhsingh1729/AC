#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long)((a) - (b) * floor((long double)(a) / (b))))
#define FIXIO                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pre(r, l) for (ll i = (r); i >= ll((l)); i--)
#define fro(l, r) for (ll i = (l); i <= ll((r)); i++)

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> edges(m);

  vector<ll> inDegree(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].first >> edges[i].second;
    inDegree[edges[i].second]++;
  }
  sort(edges.begin(), edges.end());

  // topo sort (kahn)
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (inDegree[i] == 0)
      q.push(i);

  ll c = 1;
  vector<ll> topo(n + 1);
  while (!q.empty()) {
    ll cur = q.front();
    q.pop();
    topo[cur] = c++;
    auto itr =
        lower_bound(edges.begin(), edges.end(), cur,
                    [&](auto &itr, auto &val) { return itr.first < val; });
    while (itr->first == cur) {
      inDegree[itr->second]--;
      if (inDegree[itr->second] == 0)
        q.push(itr->second);
      itr++;
    }
  }
  sort(edges.begin(), edges.end(),
       [&](auto &a, auto &b) { return topo[a.first] < topo[b.first]; });

  // DP
  vector<ll> dp(n + 1);
  for (int i = 0; i < m; i++) {
    dp[edges[i].second] = max(dp[edges[i].second], dp[edges[i].first] + 1);
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
  FIXIO;

  ll t;
  t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}