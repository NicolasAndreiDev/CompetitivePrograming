#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, l0 = 0, r1 = 0; cin >> n; n++;
    vector<int> pref(n, 0), suf(n, 0);
    string s; cin >> s;
    
    pref[1] = s[0] == '0' ? 1 : 0;
    if(pref[1] == 1) l0++;
    else r1++;

    for(int i=2;i<n;i++) {
        pref[i] = s[i - 1] == '0' ? pref[i - 1] + 1 : pref[i - 1];
        
        if(s[i - 1] == '1') r1++;
        else l0++;
    }
    
    suf[0] = r1;
    suf[1] = s[0] == '1' ? suf[0] - 1 : suf[0];
    for(int i=2;i<n;i++) {
        suf[i] = s[i - 1] == '1' ? suf[i - 1] - 1 : suf[i - 1];
    }
    
    bool ok1 = false, ok2 = false;
    int mid = (n - 1) / 2, mid2 = (n - 1) / 2;
    for(int i=0;i<=n/2;i++) {
        if(mid2 >= 0) {
            if(pref[mid2] >= (float)mid2 / 2 && suf[mid2] >= (float)(n - 1 - mid2) / 2) ok1 = true;
        }

        if(mid < n) {
            if(pref[mid] >= (float)mid / 2 && suf[mid] >= (float)(n - 1 - mid) / 2) ok2 = true;
        }

        if(ok1 || ok2) break;

        mid++, mid2--;
    }

    if(ok1 && ok2) {
        if(abs(float(n-1) / 2 - mid) < abs(float(n-1) / 2 - mid2)) cout << mid << endl;
        else cout << mid2 << endl;
    }
    else if(ok2) cout << mid << endl;
    else cout << mid2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}