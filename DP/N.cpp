#include <bits/stdc++.h>
#include <climits>

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
  vector<ll> A(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> A[i];

  for (int i = 1; i <= n; i++)
    A[i] += A[i - 1];

  vector dp(n, vector(n, LONG_LONG_MAX));

  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
  }

  for (int s = 2; s <= n; s++) {
    for (int l = 0; l < n; l++) {
      int r = l + s - 1;
      if (r < n) {
        for (int m = l; m < r; m++) {
          dp[l][r] = min(
            dp[l][r],
            dp[l][m] + dp[m+1][r] + (A[r+1] - A[m+1]) + (A[m+1] - A[l])
          );
        }
      } else {
        break;
      }
    }
  }

  cout << dp[0][n - 1] << '\n';
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