#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 9;

int vis[MAXN][MAXN];
map<ii, int> dist;
vector<ii> mov = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};

bool val(int i, int j) {
    return i>=0 and j>=0 and i<8 and j<8 and !vis[i][j];
}

void bfs(int i, int j) {
    queue<ii> q;
    q.push({i, j}), vis[i][j] = 1, dist[{i, j}] = 0;

    while(!q.empty()) {
        ii re = q.front(); q.pop();
        for(int k=0;k<8;k++) {
            int new_i = re.first+mov[k].first, new_j = re.second+mov[k].second;
            if(val(new_i, new_j)) {
                q.push({new_i, new_j}), vis[new_i][new_j] = 1, dist[{new_i, new_j}] = dist[{re.first, re.second}] + 1;
            }
        }
    }
}

void solve() {
    memset(vis, 0, sizeof vis), dist.clear();
    string a, b; cin >> a >> b;
    a[0] -= 'a', b[0] -= 'a';
    
    bfs((int)b[0], abs((int)b[1] - '0' - 8));

    int ans = dist[{(int)a[0], abs((int)a[1] - '0' - 8)}];
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if (tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
