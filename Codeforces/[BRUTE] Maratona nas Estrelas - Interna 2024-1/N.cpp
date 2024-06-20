#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<ll, int> ii;
typedef tuple<int, int, int> tiii;

void solve() {
    int n, m, q; cin >> n >> m >> q;

    unordered_map<int, int> col, lin;

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int a, b; cin >> a >> b;
            lin[a] = 1;
            col[b] = 1;
        } else {
            int x, y, xf, yf; cin >> x >> y >> xf >> yf;
            if((lin[x] && lin[xf]) || (col[y] && col[yf]) || (lin[x] && col[yf]) || (lin[xf] && col[y])) cout << "SIM" << endl;
            else cout << "NAO" << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}