#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(k+1), b(k+1);
    for(int i=1;i<=k;i++) cin >> a[i];
    for(int i=1;i<=k;i++) cin >> b[i];

    while(q--) {
        int p; cin >> p;
        auto it = lower_bound(a.begin(), a.end(), p);
        int i = it - a.begin();

        double calc;
        if(i == 0) {
            cout << 0 << " ";
            continue;
        } else {
            calc = b[i - 1] + (double)(p - a[i - 1]) * (b[i] - b[i - 1]) / (a[i] - a[i - 1]);
            cout << (int)calc << " ";
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}