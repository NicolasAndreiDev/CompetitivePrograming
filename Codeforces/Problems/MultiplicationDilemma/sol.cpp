#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int x, y; cin >> x >> y;
    int a = 0, b = 0, c = 0, d = 0;
    if(x % 10 != 0) {
        a = (x / 10 + 1) * 10;
        b = (10 - x % 10);
    }

    if(y % 10 != 0) {
        c = (y / 10 + 1) * 10;
        d = (10 - y % 10);
    }

    if(!a && !b && !c && !d) cout << x << " x " << y << endl;
    else if(!c && !d) cout << a << " x " << y << " - " << b << " x " << y << endl;
    else if(!a && !b) cout << x << " x " << c << " - " << x << " x " << d << endl;
    else cout << a << " x " << c << " + " << b << " x " << d << " - " << a << " x " << d << " - " << b << " x " << c << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if (tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
