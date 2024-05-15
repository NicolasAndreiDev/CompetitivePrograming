#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    ll P, X; cin >> P >> X;

    if(X == 2) cout << P * 3 << endl;
    else cout << P * 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}