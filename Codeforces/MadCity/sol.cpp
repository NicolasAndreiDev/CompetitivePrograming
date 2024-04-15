#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5+5;
vector<vector<int>> adj(MAXN);
vector<int> vis(MAXN), dist(MAXN);

bool dfs(int *node, int v, int p) {
    if(vis[v]) {
        *node = v;
        return true;
    }
    vis[v] = 1;

    for(auto& u:adj[v]) {
        if(u != p) {
            if(dfs(node, u, v)) return true;
        }
    }

    return false;
}

bool bfs(int node, int n, int m, int v) {
    queue<int> q; q.push(node);

    vis.assign(MAXN, 0);
    dist[node] = 0, vis[node] = 1;

    while(!q.empty()) {
        int val = q.front(); q.pop();
        for(auto& u:adj[val]) {
            if(!vis[u]) {
                q.push(u), vis[u] = 1;
                dist[u] = dist[val] + 1;
            }
        }
    }

    return dist[v] < dist[m];
}

void solve() {
    int n, m, v; cin >> n >> m >> v; m--, v--;
    dist.assign(n, 0), vis.assign(n, false), adj.assign(n, vector<int>());

    for(int i=0;i<n;i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int node = -1;
    if(m == v) {
        cout << "NO" << endl;
    } else {
        dfs(&node, v, -1);
        if(node != -1) cout << (bfs(node, n, m, v) ? "YES" : "NO") << endl;
        else cout << "NO" << endl;
    }
}   

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}