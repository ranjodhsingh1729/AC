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
  int n, w;
  cin >> n >> w;
  vector<pair<int, int>> A(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> A[i].second >> A[i].first;

  vector<ll> dp(1e5 + 1, INT_MAX);

  dp[0] = 0;
  for (int j = 1; j <= n; j++) {
    for (int i = 1e5; i >= A[j].first; i--) {
      dp[i] = min(dp[i], dp[i - A[j].first] + A[j].second);
    }
  }

  ll ans = 0;
  for (int i = 0; i <= 1e5; i++) {
    if (dp[i] <= w)
      ans = i;
  }

  cout << ans << endl;
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