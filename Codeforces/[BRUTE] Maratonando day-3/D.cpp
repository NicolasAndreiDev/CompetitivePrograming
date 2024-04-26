#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

ll n, h;
vector<ll> m;

ll binarySearch() {
    ll l = 1, r = 1e18+5;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        
        ll damage = 0;
        for(int i=0;i<n-1;i++) damage += min(mid, m[i + 1] - m[i]);
        damage += mid;

        if(damage >= h) r = mid - 1;
        else l = mid + 1;
    } 

    return l;
}

void solve() {
    cin >> n >> h;
    m.resize(n);

    for(auto& i:m) cin >> i;
    cout << binarySearch() << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}