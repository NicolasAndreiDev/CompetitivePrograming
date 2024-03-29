#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5+5;

vector<vector<int>> adj(MAXN);
vector<bool> vis(MAXN);
vector<int> cnt(MAXN);
vector<int> comp;

void dfs(int v){
    vis[v] = 1;
    comp.push_back(v);

    for(auto u:adj[v]) if(!vis[u]) dfs(u);
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    } 

    int ans = 0;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            comp.clear(), dfs(i);
            bool ok = true;
            for(auto u:comp) ok &= cnt[u] == 2;
            if(ok) ans++;
        }
    }
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}
