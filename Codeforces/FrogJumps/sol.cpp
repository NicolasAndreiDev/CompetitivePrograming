#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

int binarySearch(string s, int n) {
    int l = 1, r = n+1;
    
    while(l <= r) {
        int last = -1;
        int mid = l + (r - l) / 2;
        
        auto check = [&]() {
            while(last < n) {
                if(last + mid >= n) return 1;
        
                bool ok = 0;
                for(int i=1;i<=mid;i++) {
                    if(s[i+last] == 'R') {
                        last+=i;
                        ok = 1;
                        break;
                    }
                }

                if(!ok) return 0;
            }
        };

        if(check()) r = mid - 1; 
        else l = mid + 1;
    }
    
    return l;
}

void solve() {
    string s; cin >> s;
    cout << binarySearch(s, s.size()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}
