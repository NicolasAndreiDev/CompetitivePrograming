#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

vector<vector<ii>> val(1005);

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

void solve() {
    int n; cin >> n;
    set<int> ele;
    map<int, int> m;
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        ele.insert(x);
        m[x] = i;
    }
    
    int ans = -1;
    for(auto&i:ele) {
        for(auto j:val[i]) {
            if(m[j.first] != 0 && m[j.second] != 0) {
                ans = max(ans, m[j.first] + m[j.second]);
            }
        }
    }
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        for(int i=1;i<=1000;i++) {
            for(int j=1;j<=1000;j++) {
                if((gcd(i, j) == 1)) val[i].push_back({i, j});
            }
        }
        while(t--) solve();
    } else solve();
}