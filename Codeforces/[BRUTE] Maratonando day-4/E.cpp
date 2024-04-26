#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, k; cin >> n >> k;
    map<char, int> m;

    string s; cin >> s;
    for(int i=0;i<n;i++) m[s[i]]++;

    int ans = 0;
    for(int i=0;i<26;i++) {
        if(m['a' + i] == m['A' + i]) ans += m['a' + i];
        else if(m['a' + i] + m['A' + i] > 1) {
            int pairs = min(m['a' + i], m['A' + i]);
            ans += pairs;
            m['a' + i] -= pairs, m['A' + i] -= pairs;
            int add = min(k, max(m['a' + i], m['A' + i]) / 2);
            k -= add; 
            ans += add;
        }   
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