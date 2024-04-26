#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n; cin >> n;
    vector<ll> m(n);
    for(auto&i:m) cin >> i;

    ll p1 = 1, p2 = 1;
    sort(m.begin(), m.end());
    p1 *= m[0], p1 *= m[1];
    p2 *= m[n-2], p2 *= m[n-1];

    cout << max(p1, p2) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}