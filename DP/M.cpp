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
  ll n, k;
  cin >> n >> k;
  vector A(n, 0LL);
  for (auto &i : A)
    cin >> i;

  vector<ll> dp(k + 1);

  for (int i = 0; i <= k; i++)
    dp[i] = (i <= k);

  for (int i = 0; i < n; i++) {
    for (int s = k; s >= 0; s--)
      dp[s] = dp[s] - (s - A[i] > 0 ? dp[s - A[i] - 1] : 0);

    for (int i = 1; i <= k; i++)
      dp[i] = mod(dp[i] + dp[i - 1], 1e9 + 7);
  }

  if (k == 0) {
    cout << 1 << endl;
  } else {
    cout << mod(dp[k] - dp[k - 1], 1e9 + 7) << endl;
  }
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