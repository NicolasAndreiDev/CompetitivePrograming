#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

int n;
vector<int> m;

int binarySearch() {
    int l = 0, r = n - 2;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        
        auto check = [&]() {
            int lp = mid, rp = n - 1, last = -1;
            
            bool ok = 1;
            for(int i=mid;i<n;i++) {
                if(m[lp] <= m[rp] && m[lp] >= last) last = m[lp], lp++;
                else if(m[rp] <= m[lp] && m[rp] >= last) last = m[rp], rp--;
                else {ok = 0; break;}
            }
            
            return ok;
        };
        
        if(check()) r = mid - 1;
        else l = mid + 1; 
    }

    return l;
}

void solve() {
    cin >> n; m.resize(n);
    for(auto& i:m) cin >> i;
    cout << binarySearch() << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}
