#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n; cin >> n;
    vector<int> m(n+1);
    int neg = 0, ze = 0, pos = 0;

    for(int i=1;i<=n;i++) {
        cin >> m[i];
        
        if(m[i] < 0) neg++;
        else if(m[i] > 0) pos++;
        else ze++;
    }

    if(ze || neg % 2 != 0) cout << 0 << endl;
    else {
        cout << 1 << endl;
        cout << 1 << " " << 0 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}
    