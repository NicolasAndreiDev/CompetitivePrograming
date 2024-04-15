#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, s; cin >> n >> s;
    vector<int> m(n);
    for(auto& i:m) cin >> i;

    int ans = 0;
    for(int mask=1;mask<(1<<n);mask++){
        int sum=0, size=0, minVal=1e9;
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                sum += m[i];
                size++;
                minVal = min(minVal, m[i]);
            }
        }

	    if(sum>=s && minVal>sum-s) ans = max(ans, size);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}