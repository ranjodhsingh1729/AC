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
    ll n;
    cin >> n;
    vector<int> A(n);
    map<int, int> freq;
    map<int, int> preq;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        // ADD TO LEFT
        preq[A[i]]++;
        freq[A[i]]--;

        if (freq[A[i]] == 0) {
            freq.erase(A[i]);
        }

        mx = max(mx, preq.size()+freq.size());
    }

    cout << mx << '\n';
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