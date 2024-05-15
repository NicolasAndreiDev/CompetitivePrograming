#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

void solve(){
    ll n, x; cin >> n >> x;
    vector<int> m(n);
    for(auto&i:m) cin >> i;
    sort(m.begin(), m.end(), greater<int>());

    ll ans = m[0], qtd = 1;
    for(int i=1;i<n;i++){ 
        ull atual = i * (m[i - 1] - m[i]);
        if(atual <= x){
            ans = m[i];
            x -= atual;
        } else goto end;
        qtd++;
    }

    end:
    if(x == 0) cout << ans << endl;
    else if((float)x / qtd == 0) cout << max(ans-1, 0LL) << endl;
    else cout << max(ans-(x / qtd), 0LL) << endl;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc){
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}