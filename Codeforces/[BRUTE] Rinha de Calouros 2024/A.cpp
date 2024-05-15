#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> m(n);
    for(auto&i:m) cin >> i;

    multimap<int, int> val;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        if(x == 1) val.insert({m[i], 1});
        else val.insert({m[i], 0});
    }   

    int ans = 0;
    bool ok = true;
    for(auto it=val.begin();it!=val.end();it++) {
        if(it->second == 1 && ok) {
            ok = false;
            if(k - it->first >= 0) {
                k -= it->first;
                ans++;
            }
        } else {
            if(k - it->first >= 0 && it->second != 1) {
                k -= it->first;
                ans++;
            }
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