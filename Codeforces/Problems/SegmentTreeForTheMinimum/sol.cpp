#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5+5;
vector<ll> me(4*MAXN);

void build(int i, int v, int x, int lx, int rx) {
    if(rx - lx == 1) {me[x] = v; return;}
    int m = (lx + rx) / 2;
    if(i < m) build(i, v, 2 * x + 1, lx, m);
    else build(i, v, 2 * x + 2, m, rx);
    me[x] = min(me[2 * x + 1], me[2 * x + 2]);
}

ll query(int l, int r, int x, int lx, int rx) {
    if(lx >= r || l >= rx) return LLONG_MAX;
    if(lx >= l && rx <= r) return me[x];
    int m = (lx + rx) / 2;
    ll s1 = query(l, r, 2 * x + 1, lx, m);
    ll s2 = query(l, r, 2 * x + 2, m, rx);
    return min(s1, s2);
}

void update(int i, int v, int x, int lx, int rx) {
    if(rx - lx == 1) {me[x] = v; return;} 
    int m = (lx + rx) / 2;
    if(i < m) update(i, v, 2 * x + 1, lx, m);
    else update(i, v, 2 * x + 2, m, rx);
    me[x] = min(me[2 * x + 1], me[2 * x + 2]);
}

void solve() {
    int n, m; cin >> n >> m;

    int size = 1;
    while(size < n) size *= 2;
    me.assign(2 * size, LLONG_MAX);

    for(int i=0;i<n;i++) {
        int v; cin >> v;
        build(i, v, 0, 0, size);
    }

    while(m--) {
        int op; cin >> op;
        if(op == 2) {
            int l, r; cin >> l >> r;
            cout << query(l, r, 0, 0, size) << endl;
        } else {
            int p, v; cin >> p >> v;
            update(p, v, 0, 0, size);
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
