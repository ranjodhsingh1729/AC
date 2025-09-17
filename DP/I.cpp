#include <bits/stdc++.h>
#include <iomanip>

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
  cout << setprecision(12);

  ll n;
  cin >> n;
  vector<double> A(n);
  for (auto &i : A)
    cin >> i;

  /*
      DP TRANSITION:-
      Probability of getting j heads with i no of coins
      is probability of getting j heads with i-1 no of coins 
      times getting tails on the ith coin or probability of getting
      j-1 heads with i-1 coins times getting heads on the ith coin.
  */

  vector<double> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j > 0; j--) {
      dp[j] = dp[j - 1] * A[i] + dp[j] * (1 - A[i]);
    }
    dp[0] *= (1 - A[i]); // Maintaining Order
  }

  double ans = 0;
  for (int i = (n + 1) / 2; i <= n; i++) {
    ans += dp[i];
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