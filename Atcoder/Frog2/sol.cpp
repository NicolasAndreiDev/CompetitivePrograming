#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> m(n);
    for(auto &el:m) cin >> el;

    vector<int> dp(n, INF);
    dp[0] = 0;
    for(int i=0;i<n;i++) {
        for(int j=max(0, i-k);j<i;j++) {
            dp[i] = min(dp[i], dp[j] + abs(m[i] - m[j]));
        }
    }

    cout << dp[n - 1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 0;
    if (tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
