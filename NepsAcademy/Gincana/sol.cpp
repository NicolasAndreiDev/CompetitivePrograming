#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5;

vector<vector<int>> adj(MAXN);
vector<bool> vis(MAXN);

void dfs(int v){
    vis[v] = 1;
    for(auto u:adj[v]) if(!vis[u]) dfs(u);
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    } 

    int ans = 0;
    for(int i=0;i<n;i++) if(!vis[i]) dfs(i), ans++;
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
