#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    ll n, d; cin >> n >> d;
    
    if(d&1) cout << n << endl;
    else cout << n - (n / (d + 1)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}