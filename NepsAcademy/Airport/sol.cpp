#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e3+5;
int cont = 1;

void solve() {
    vector<vector<int>> adj(MAXN);
    int a, v; cin >> a >> v;
    if(a == 0 && v == 0) exit(0);
    for(int i=0;i<v;i++) {
        int b, c; cin >> b >> c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }

    int max_adj = -1;
    vector<int> val;
    for(int i=1;i<=a;i++) {
        int num = adj[i].size();
        if(num > max_adj) max_adj = num;
    }

    for(int i=1;i<=a;i++) {
        int num = adj[i].size();
        if(num == max_adj) val.push_back(i);
    }

    cout << "Teste " << cont++ << endl;
    for(int i=0;i<val.size();i++) cout << val[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    while(1) solve();
}
