#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int a, b, c; cin >> a >> b >> c;

    queue<int> q;
    q.push(0);
    int ans = 0;

    for(int i=0;i<a;i++) {
        int h = q.front(); q.pop();
        ans = h;
        q.push(h + 1), q.push(h + 1);
    }

    for(int i=0;i<b;i++) {
        int h = q.front(); q.pop();
        ans = h;
        q.push(h + 1);
    }

    for(int i=0;i<c;i++) {
        int h = q.front(); q.pop();
        ans = h;
    }
    
    cout << (q.empty() ? ans : -1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if (tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
