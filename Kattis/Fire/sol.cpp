#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000;

int n, m;
char M[MAXN][MAXN];
int vis[MAXN][MAXN];
int dist[MAXN][MAXN];

vector<ii> mov = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool val(ii u) {
    return u.first >= 0 and u.second >= 0 and u.first < n and u.second < m
        and M[u.first][u.second] != '#' and !vis[u.first][u.second];
}

void bfs_ms(vector<ii> ms) {
    memset(vis, 0, sizeof vis);
    memset(dist, INF, sizeof dist);

    queue<ii> q;
    for(auto s:ms) q.push(s), vis[s.first][s.second] = 1, dist[s.first][s.second] = 0;

    while(!q.empty()) {
        ii v = q.front(); q.pop();

        for(auto u:mov) {
            u.first += v.first, u.second += v.second;
            if(val(u)) {
                q.push(u), vis[u.first][u.second] = 1;
                dist[u.first][u.second] = dist[v.first][v.second]+1;
            } 
        }
    }
}

int bfs(ii s) {
    memset(vis, 0, sizeof vis);
    queue<ii> q; 
    q.push(s), vis[s.first][s.second] = 1, dist[s.first][s.second] = 0;

    while(!q.empty()) {
        ii v = q.front(); q.pop();

        if(v.first == 0 || v.second == 0 || v.first == n-1 || v.second == m-1) {
            return dist[v.first][v.second]+1;
        }

        for(auto u:mov) {
            u.first += v.first, u.second += v.second;
            if(val(u) && dist[v.first][v.second] + 1 < dist[u.first][u.second]) {
                q.push(u), vis[u.first][u.second] = 1;
                dist[u.first][u.second] = dist[v.first][v.second]+1;
            }
        }
    }

    return -1;
}

void solve() {
    cin >> m >> n;

    vector<ii> ms;
    ii s;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin >> M[i][j];
        if(M[i][j] == '*') ms.push_back({i, j});
        if(M[i][j] == '@') s = {i, j};
    }

    bfs_ms(ms);
    int ans = bfs(s);
    cout << (ans != -1 ? to_string(ans) : "IMPOSSIBLE") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if (tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
