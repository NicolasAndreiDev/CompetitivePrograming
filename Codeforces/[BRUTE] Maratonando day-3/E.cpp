#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n; cin >> n;
    vector<int> m(n);
    for(auto& i:m) cin >> i;

    vector<int> par, impar;
    vector<int> ipar, iimpar;
    for(int i=0;i<n;i++) { 
        if(m[i] % 2 == 0) {
            par.push_back(m[i]);
            ipar.push_back(i);
        } else {
            impar.push_back(m[i]);
            iimpar.push_back(i);
        }
    }

    vector<int> ans(n, 0);
    sort(par.begin(), par.end());
    sort(ipar.begin(), ipar.end());
    sort(impar.begin(), impar.end());
    sort(iimpar.begin(), iimpar.end());

    for(int i=0;i<par.size();i++) {
        ans[ipar[i]] = par[i];
    }

    for(int i=0;i<impar.size();i++) {
        ans[iimpar[i]] = impar[i];
    }

    bool ok = is_sorted(ans.begin(), ans.end());
    cout << (ok ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}