#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int N, Q; cin >> N >> Q;
    vector<vector<int>> adj(N+5);

    for(int i=0;i<N-1;i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(Q--) {
        int L, E, S; cin >> L >> E >> S; L--, E--, S--;
        queue<int> pil; pil.push(L);
        vector<int> dist(N+5, 1);
        vector<int> vis(N+5);

        while(!pil.empty()) {
            int val = pil.front(); pil.pop();
            for(auto u:adj[val]) {
                if(!vis[u]) {
                    pil.push(u); vis[u] = 1;
                    dist[u] = (u == S ? dist[val] * -1 : dist[val] * 1);
                }
            }
        }

        cout << (dist[E] == -1 ? "NAO" : "SIM") << endl;
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