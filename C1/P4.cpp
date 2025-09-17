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

#define is_cbrt(n) (ceill(cbrtl((n))) == floorl(cbrtl((n))))
#define P_OF_LL(a, b) ((b) > 0 && (a) > LONG_LONG_MAX - (b))

void solve() {
    ll n;
    cin >> n;

    for (ll i = 1; i <= 1000000; i++) {
        if (P_OF_LL(n, i*i*i))
            break;

        if (is_cbrt(n+i*i*i)) {
            cout << ll(floorl(cbrtl(n+i*i*i))) << ' ' << i << '\n';
            return;
        }
    }
    
    cout << -1 << '\n';
    return;
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