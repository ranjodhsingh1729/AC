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

//   There is a little problem here in our representation.

//   x is a man and y is a women now its just me or do you see the problem. So
//   how should this be represented.

//   what is 2 ^ 21? it should be 2 * 1024 * 1024 ~ 2e6. if dp[S][i] = 4e7.

//   So because each step uses subsets of len one less than current.
//   we would start from all zeroes and one 1 anywhere and two ones
//   again anywhere and so on.

//   how will you generate such a order:- start is from 0 and add one when
//   jumping levels then all we need to do is at each step keep the no of 1's
//   same from increasing but how?

//   0
//   2^x
//   and then 2^x + 2^y ( x != y )
//   and then 2^x + 2^y + 2^z ( x != y != z )

//   where each value can go up to 21 from -1 (implying not there yet) ?
//   but still are seriously considering 21 loops ? WHAT? ARE YOU SERIOUS?

void solve() {
  ll n;
  cin >> n;
  vector A(n, vector(n, 0LL));
  for (auto &i : A) {
    for (auto &j : i) {
      cin >> j;
    }
  }

  /*

  Since All Men and Women Have Different Matching Possiblities
  State Should Reflect That Therefore State Can't Be Just The No.
  of matchings till and index, it should reflect which `subset` of
  men or women took part in the matching.

  The question can be solved from the perspective of men or wemen.
  (Both would be equavalent). This much is obvious from the input
  matrix being symmetric if aij is a match then so is aji matches
  are not ordered.

  Now lets decide what the state of the dp should be:-

  - Since we are interested in subsets we will use a bitmask to
    represent which indexes are included and which are not.

  - Let S be a perticular subset from all possiblities.

  dp[S] = no of matchings if only women in S take part in assuming |S| first
          men were taking part.

  So the transition state can look like:-

  dp[S] = summation{ dp[S \ y] } for a y which can be a companion for |S| th
  man.

  Order of Dp:-

  just the order of natural numbers i guess upto 1 << N;
  */

  vector<ll> dp((1 << n) + 1);

  dp[0] = 1;
  for (int s = 1; s < (1 << n); s++) {
    ll c = 0;

    for (int i = 0; i <= 21; i++)
      c += bool(s & (1 << i));

    ll sum = 0;
    for (int i = 0; i < n; i++) {
      if (A[c-1][i]) {
        sum = mod(sum + dp[s & ~(1 << i)], (ll)1e9 + 7);
      }
    }
    dp[s] = sum;
  }

  cout << dp[(1 << n) - 1] << '\n';
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