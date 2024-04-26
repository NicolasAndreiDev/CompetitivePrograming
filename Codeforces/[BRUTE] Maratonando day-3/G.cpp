#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    string s; cin >> s;
    int n = s.size();
    
    if(n % 2 != 0) cout << "NO" << endl;
    else {
      cout << (s.substr(0, n / 2) == s.substr(n / 2, n / 2) ? "YES" : "NO") << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}
    