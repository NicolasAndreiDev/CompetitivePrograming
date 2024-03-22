#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1000;

ii pe;
int n, m;
int pi, pj;
char M[MAXN][MAXN];
int vis[MAXN][MAXN];
map<ii, ii> pai;
vector<ii> mov = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int path(int i, int j) {
    int cnt = 0;
    ii v = pai[{i, j}];
    while(v != pe) {
        i = v.first;
        j = v.second;
        v = pai[{i, j}];
        cnt++;
    }

    return cnt;
}

bool val(int i, int j) {
    return i>=0 and j>=0 and i<n and j<m and (M[i][j] == '1' || M[i][j] == '3') and !vis[i][j];
}

void bfs(int i, int j) {
    queue<ii> q;
    q.push({i, j}), vis[i][j] = 1, pai[{i, j}] = {i, j};

    while(!q.empty()) {
        ii re = q.front(); q.pop();
        for(int k=0;k<4;k++) {
            int new_i = re.first+mov[k].first, new_j = re.second+mov[k].second;
            if(val(new_i, new_j)) {
                if(M[new_i][new_j] == '3') pi = new_i, pj = new_j; 
                q.push({new_i, new_j}), vis[new_i][new_j] = 1, pai[{new_i, new_j}] = {re.first, re.second};
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    
    int a = 0, b = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin >> M[i][j];
        if(M[i][j] == '2') a = i, b = j, pe = {i, j};
    }

    bfs(a, b);
    cout << path(pi, pj) + 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 0;
    if (tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
