#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n; cin >> n;
    vector<int> m(n);
    for(auto &el:m) cin >> el;

    map<int, int> map;
    for(int i=0;i<n;i++) {
        int p = i;
        for(int j=i;j<n;j++) {
            if(m[p] > m[j]) p = j;
        }
        if(i != p) map.insert({i, p});
        swap(m[i], m[p]);
    }

    cout << map.size() << endl;
    for(auto el:map) cout << el.first << " " << el.second << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 0;
    if (tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
