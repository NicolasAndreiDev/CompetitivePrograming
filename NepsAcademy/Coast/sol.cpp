#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e3+5;

int m, n; 
char ma[MAXN][MAXN];
int vis[MAXN][MAXN]; 

vector<ii> mov = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool val(int i, int j) {
    return i >= 0 and j >= 0 and i < m and j < n and ma[i][j] == '#';
}

int dfs(int cnt){
    int ans = cnt;

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(ma[i][j] == '#') {
                int cont = 0;
                for(auto& u:mov) {
                   int pi = i + u.first, pj = j + u.second;
                   if(val(pi, pj)) cont++;
                }
                if(cont == 4) ans--;
            }
        }
    }

    return ans;
}

void solve() {
    cin >> m >> n;
    int cnt = 0;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
        cin >> ma[i][j];
        if(ma[i][j] == '#') cnt++;
    }

    cout << dfs(cnt) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}
