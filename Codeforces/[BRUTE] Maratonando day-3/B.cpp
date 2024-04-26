#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 4005;
int n, ans;
vector<vector<int>> adj(MAXN);
vector<char> cor(MAXN);
vector<vector<int>> dp(MAXN, vector<int>(2));

void dfs(int v) {
    if(cor[v] == 'B') dp[v][0] = 1;
    else if(cor[v] == 'W') dp[v][1] = 1;
 
    for(auto u:adj[v]){
        dfs(u);
        dp[v][0] += dp[u][0];
        dp[v][1] += dp[u][1];
    }
 
    if(dp[v][0] == dp[v][1]) ans++;
}

void solve() {
    ans = 0;
    cin >> n;

    for(int i=2;i<=n;i++) {
        int a; cin >> a;
        adj[a].push_back(i);
    }

    for(int i=1;i<=n;i++) cin >> cor[i];
    
    dfs(1);
    cout << ans << endl;
    cor.assign(MAXN, ' '), adj.assign(MAXN, vector<int>()), dp.assign(MAXN, vector<int>(2, 0));
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}