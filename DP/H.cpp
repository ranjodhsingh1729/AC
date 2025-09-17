#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pre(r, l) for (ll i = (r); i >= ll((l)); i--)
#define fro(l, r) for (ll i = (l); i <= ll((r)); i++)


void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (auto &i: grid) {
        for (auto &j: i) {
            cin >> j;
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(m));

    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
        if (grid[i][0] == '.')
            dp[i][0] = dp[i-1][0];
    for (int j = 1; j < m; j++)
        if (grid[0][j] == '.')
            dp[0][j] = dp[0][j-1];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == '.')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % (ll)(1e9+7);
        }
    }

    cout << dp[n-1][m-1] << '\n';
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