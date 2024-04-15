#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n; cin >> n;
    vector<ll> m(n+1), p(n+1);
    priority_queue<ll, vector<ll>, greater<ll>> q;

    for(int i=1;i<=n;i++) cin >> m[i];
    for(int i=1;i<=n;i++) cin >> p[i];

    ll ans = 0, x = 0;
    for(int i=n;i>=1;i--) {
        q.push(m[p[i]]);
        while(q.size() > i) q.pop();
        if(q.size() == i && q.top() * i >= ans) {
            ans = q.top() * i;
            x = i;
        }
    }

    cout << ans << " " << x << endl;
}   

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}