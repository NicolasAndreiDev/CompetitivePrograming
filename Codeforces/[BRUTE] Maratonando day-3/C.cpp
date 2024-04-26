#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n; cin >> n;
    vector<int> m(n);
    map<int, int> val;
    for(int i=0;i<n;i++) {
        cin >> m[i];
        val[m[i]]++;
    }

    reverse(m.begin(), m.end());
    int ans = 0;
    for(int i=0;i<n;) {
        if(val[m[i]] > 1) {
            ans++;
            val[m[m.size()-1]]--;
            m.pop_back();
        } else i++;
    }
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}
    