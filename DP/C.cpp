#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
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
  int n;
  cin >> n;
  vector<vector<ll>> A(n, vector<ll>(3));

  for (int i = 0; i < n; i++) {
    cin >> A[i][0] >> A[i][1] >> A[i][2];
  }

  for (int i = 1; i < n; i++) {
    A[i][0] += max(A[i - 1][1], A[i - 1][2]);
    A[i][1] += max(A[i - 1][0], A[i - 1][2]);
    A[i][2] += max(A[i - 1][0], A[i - 1][1]);
  }

  cout << std::max({A[n - 1][0], A[n - 1][1], A[n - 1][2]}) << '\n';
}

int main() {
  FIXIO;

  ll t;
  t = 1;
  //   cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}