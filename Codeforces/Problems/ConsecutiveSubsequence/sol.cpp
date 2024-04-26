#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n; cin >> n;
    vector<int> m(n+1);
    map<int, int> dp;  
    int ans = 0, last = 0;
    for(int i=1;i<=n;i++) {
        cin >> m[i];
        int val = m[i];
        dp[val] = dp[val - 1] + 1;
        if(ans < dp[val]) {
            ans = dp[val];
            last = val;
        }
    }

    vector<int> res;
    for(int i=n;i>=1;i--) {
        if(m[i] == last) {
            res.push_back(i);
            --last;
        }
    }
    reverse(res.begin(), res.end());

    cout << ans << endl;
    for(auto& i:res) cout << i << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 0;
    if (tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
