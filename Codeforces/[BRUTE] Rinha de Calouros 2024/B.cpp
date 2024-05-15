#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> val(m+1);
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        val[x]++;
    }

    int ma = *max_element(val.begin(), val.end());
    int ans = 0;
    bool ok = false;
    for(int i=1;i<=m;i++) {
        if(ok && val[i] == ma) ans += val[i];
        
        if(val[i] < ma) ans += val[i];
        else if(val[i] == ma) ok = true;
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