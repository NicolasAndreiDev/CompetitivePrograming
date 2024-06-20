#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<ll, int> ii;
typedef tuple<int, int, int> tiii;

void solve() {
    int a, b; cin >> a >> b;
    cout << a - b << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}