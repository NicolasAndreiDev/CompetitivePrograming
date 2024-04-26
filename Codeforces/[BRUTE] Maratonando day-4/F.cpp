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

    vector<ll> v(n+1); v[0] = 0;
    for(int i=1;i<=n;i++) v[i] = v[i - 1] + m[i - 1];

    int pref = 1, mid = n-1, suf = n;
    ll val = max(v[pref], max(v[mid] - v[pref], v[suf] - v[mid]));
    ll ans = val;

    for(int i=0;i<n;i++) {
        if(v[pref] > (v[mid] - v[pref]) && v[pref] > (v[suf] - v[mid]) && v[pref - 1] < ans) pref = max(1, pref-1);
        else if((v[suf] - v[mid]) > v[pref] && (v[suf] - v[mid]) > (v[mid] - v[pref]) && (v[suf] - v[mid - 1]) < ans) mid = min(n-1, mid+1);
        else {
            if(v[pref + 1] < ans && (v[pref + 1] < (v[suf] - v[mid - 1]))) pref = min(n-2, pref+1);
            else if((v[suf] - v[mid - 1]) < ans) mid = max(2, mid-1);
            else goto end;
        }
            
        val = max(v[pref], max(v[mid] - v[pref], v[suf] - v[mid]));
        ans = min(ans, val);
    }

    end:
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}