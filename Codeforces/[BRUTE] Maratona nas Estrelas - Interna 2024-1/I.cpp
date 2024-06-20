#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 998244353
#define INF 0x3f3f3f3f

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef tuple<int, int, int> tiii;

void solve() {
    int n; cin >> n;

    vector<int> m(n); 
    ull soma = 0;
    for(auto&i:m) {
        cin >> i; 
        soma += i;
    }

    int qtd = 1;
    ull val = 0;
    for(int i=0;i<n;i++) {
        ull prev = val;        
        val |= m[i];
 
        if((prev + m[i]) > val) {
            qtd++;
            val = m[i];
        }
    }

    cout << soma << " " << qtd << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}