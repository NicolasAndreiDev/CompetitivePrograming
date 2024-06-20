#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> tiii;

void solve() {
    ll n, k, x; cin >> n >> k >> x;
    vector<ii> m(n);
    for(auto&i:m) cin >> i.first >> i.second;
    
    ll e = 0;
    vector<ll> dp(n+1, -LLONG_MAX);
    for(int i=0;i<n;i++) {
        dp[min(i+k, n)] = max(dp[min(i+k, n)], e-x);
        e = max(e+m[i].second, dp[i]);
        dp[i+1] = max(dp[i+1],e-m[i].first);
        
        if(dp[i+1] > e-m[i].first) e = dp[i+1];
        else e -= m[i].first;
    }
    
    cout << max(dp[n], 0LL) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}