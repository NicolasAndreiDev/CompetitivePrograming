#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int p = s.find('1');
    int ans = 0;
    for(int i=max(p, 0);i+1<n;i++) {
        if(s[i] != s[i + 1]) ans++;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}