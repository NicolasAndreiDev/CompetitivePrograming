#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, w; cin >> n >> w;
    vector<ii> item(n);
    for(auto& i:item) cin >> i.first >> i.second;
    
    vector<ll> dp(w+1);
    for(int i=0;i<n;i++) {
        for(int j=w-item[i].first;j>=0;j--) {
            dp[j + item[i].first] = max(dp[j + item[i].first], dp[j] + item[i].second);
        }
    }

    ll ans = 0;
    for(int i=0;i<=w;i++) ans = max(ans, dp[i]);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 0;
    if (tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
