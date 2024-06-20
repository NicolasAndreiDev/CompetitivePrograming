#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<ll, int> ii;
typedef tuple<int, int, int> tiii;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> m(n+1); for(int i=1;i<=n;i++) cin >> m[i];

    vector<int> ans;
    for(int i=1;i<=n;i++) {
        if(k == 0) ans.push_back(i);
        else if(k % m[i] == 0) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(auto u:ans) cout << u << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}