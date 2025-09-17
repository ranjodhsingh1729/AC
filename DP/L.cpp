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
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (auto &i : A)
    cin >> i;

  vector dp(n, vector(n, vector<ll>(2)));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 1) {
        dp[j][j + i - 1][0] = A[j];
        dp[j][j + i - 1][1] = -A[j];
      } else if (j+i-1 < n) {
        dp[j][j + i - 1][0] = max(dp[j + 1][j + i - 1][1] + A[j],
                                  dp[j][j + i - 2][1] + A[j + i - 1]);
        dp[j][j + i - 1][1] = min(dp[j + 1][j + i - 1][0] - A[j],
                                  dp[j][j + i - 2][0] - A[j + i - 1]);
      }
    }
  }

  cout << dp[0][n-1][0] << endl;
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