#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef tuple<int, int, int> tiii;

const int maxn = 3*1e5+5;
vector<vector<ii>> adj(maxn);
vector<ll> d(maxn, LLONG_MAX);

void solve() {
    int n, m, k; cin >> n >> m >> k;

    int higgs = 0;
    for(int i=0;i<m;i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[b].push_back({a, c});
        adj[a].push_back({b, c});
        higgs = max(higgs, c);
    }

    auto bfs01 = [&](int mid) {
        deque<int> q; q.push_front(1);
        d[1] = 0;
        
        while(!q.empty()) {
            int f = q.front(); q.pop_front();
            for(auto v:adj[f]) {
                int u = v.first;
                ll w = v.second;

                int p = (w <= mid ? 0 : 1);
                if(d[f] + p < d[u]) {
                    d[u] = d[f] + p;
                    if(p == 1) q.push_back(u);
                    else q.push_front(u);
                }
            }
        }

        return d[n] <= k;
    };

    auto binarysearch = [&]() {
        int l = 0, r = higgs;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(bfs01(mid)) r = mid - 1;
            else l = mid + 1;
            for(int i=1;i<=n;i++) d[i] = INF;
        }

        cout << l << endl;
    };

    binarysearch();
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}