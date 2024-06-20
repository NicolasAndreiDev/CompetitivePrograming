#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<ll, int> ii;
typedef tuple<int, int, int> tiii;

void solve() {
    int n; cin >> n;
    vector<ll> m(n); for(auto&i:m) cin >> i;
    
    auto ma = max_element(m.begin(), m.end());
    vector<ll> aux; for(int i=ma-m.begin();i<n;i++) aux.push_back(m[i]);

    ll ans = *ma + 2 + (ma - m.begin());
    ll tam = *ma;
    for(int i=1;i<aux.size();i++) {
        tam--;
        if(tam < aux[i]) {
            ans += aux[i] - tam;
            tam = aux[i];
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}