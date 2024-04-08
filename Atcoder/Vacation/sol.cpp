#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n; cin >> n;
    vector<int> dp(3);

    for(int i=0;i<n;i++) {
        vector<int> m(3), new_dp(3, 0);
        for(auto& j:m) cin >> j;

        for(int k=0;k<3;k++) {
            for(int l=0;l<3;l++) {
                if(k != l) new_dp[l] = max(new_dp[l], dp[k] + m[l]);
            }
        }
        dp = new_dp;
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 0;
    if (tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
