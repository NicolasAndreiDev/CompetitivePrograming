#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<ll, int> ii;
typedef tuple<int, int, int> tiii;

void solve() {
    string s; cin >> s;
    int n; cin >> n;
    
    map<char, set<char>> alf;
    while(n--) {
        char a, b; cin >> a >> b;
        alf[b].insert(a);
    }

    for(int i=1;i<s.size();i++) {
        bool ok = false;
        for(auto u:alf[s[i]]) {
            if(s[i - 1] == u) {
                ok = true;
                break;
            }
        }

        if(!ok) {
            cout << "NAO" << endl;
            return;
        }
    }

    cout << "SIM" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}