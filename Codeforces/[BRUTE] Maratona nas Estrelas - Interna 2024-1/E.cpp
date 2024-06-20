#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<ll, int> ii;
typedef tuple<int, int, int> tiii;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> m(n); for(auto&i:m) cin >> i;

    int ult = 0;
    vector<int> val;
    for(auto&i:m) {
        ult = gcd(ult, i);
        val.push_back(ult);
    }
    
    while(q--) {
        int op; cin >> op;
        if(op == 2) {
            int qtd; cin >> qtd;
            while(qtd--) {
                m.pop_back();
                val.pop_back();
            }
            if(!val.empty()) ult = val.back();
            else ult = 0;
        } else if(op == 3) {
            int qtd; cin >> qtd;
            if(ult % qtd != 0 || m.empty()) cout << "NAO" << endl;
            else if(ult == 1 && qtd != 1) cout << "NAO" << endl;
            else cout << "SIM" << endl;
        } else {
            int qtd; cin >> qtd;
            m.push_back(qtd);
            ult = gcd(ult, qtd);
            val.push_back(ult);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}