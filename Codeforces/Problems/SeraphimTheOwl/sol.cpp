#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n), v2(n);
    for(auto& i:v) cin >> i;
    for(auto& i:v2) cin >> i;

    ll ans = 0;
    for(int i=n-1;i>m-1;i--) {
        ans += min(v[i], v2[i]);
    }

    ll val = INT_MAX, sum = 0;
    for(int i=m-1;i>=0;i--){
        val = min(v[i] + sum, val);
        sum += v2[i];
    }

    cout << ans + val << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}