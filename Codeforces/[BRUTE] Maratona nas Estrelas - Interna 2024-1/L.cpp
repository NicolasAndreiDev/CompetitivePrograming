#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<ll, int> ii;
typedef tuple<int, int, int> tiii;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1);    

    while(m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> dist(n+1, 0);
    vector<vector<int>> conexoes(n+1);
    auto bfs = [&](int i) {
        queue<int> q; q.push(i); vis[i] = 1;

        while(!q.empty()) {
            int f = q.front(); q.pop();
            conexoes[dist[f]].push_back(f);

            for(auto&u:adj[f]) {
                if(!vis[u]) {
                    q.push(u); vis[u] = 1;
                    dist[u] = dist[f] + 1;
                }
            }
        }
    };

    vis.assign(n+1, 0); 
    for(int i=1;i<=n;i++) {
        if(!vis[i]) bfs(i);
    }

    bool ok = true;
    vector<int> a, b;
    for(int i=0;i<n;i++) {
        if(dist[i+1] % 2 == 0) a.push_back(i+1);
        else b.push_back(i+1);
        if(conexoes[i].size() > 1) {
            for(auto v:conexoes[i]) {
                for(auto b:adj[v]) {
                    if(dist[b] == dist[v]) ok = false;
                }
            }
        }
    }

    if(ok) {
        cout << "POSSIVEL" << endl;
        cout << a.size() << " " << b.size() << endl;
        for(auto&i:a) cout << i << " ";
        cout << endl;
        for(auto&i:b) cout << i << " ";
        cout << endl;
    } else cout << "IMPOSSIVEL" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}