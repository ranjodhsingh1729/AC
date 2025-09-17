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
    int n, w;
    cin >> n >> w;
    vector<pair<int,int>> A(n+1, {0,0});
    for (int i = 1; i <= n; i++) {
        cin >> A[i].first >> A[i].second;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(w+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - A[i].first >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i].first] + A[i].second);
            }
        }
    }

    cout << dp[n][w] << '\n';
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