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

  auto turn = [&](ll l, ll r) { return (n - (r - l + 1)) & 1; };
  auto sign = [&](ll l, ll r) { return turn(l, r) ? -1 : +1; };
  auto optim = [&](ll x, ll a, ll b) { return x ? min(a, b) : max(a, b); };

  vector<vector<ll>> dp;
  for (int i = 0; i < n; i++) {
    dp.push_back(vector<ll>(n - i, 0));
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      int l = j, r = j + i - 1;
      if (l == r) {
        dp[l][r - l] = sign(l, r) * A[l];
        continue;
      }

      if (r < n) { // l is always in bounds
        dp[l][r - l] = optim(turn(l, r), dp[l + 1][r - (l + 1)] + sign(l, r) * A[l],
                             dp[l][r - l - 1] + sign(l, r) * A[r]);
      }
    }
  }

  cout << dp[0][n - 1] << endl;
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
