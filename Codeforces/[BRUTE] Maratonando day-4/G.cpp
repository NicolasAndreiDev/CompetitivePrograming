#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n; cin >> n;
    int cnt = 0;

    vector<int> m;
    while(n > 0) {
        m.push_back(n % 10);
        n /= 10;
        cnt++;
    }

    int z = count(m.begin(), m.end(), 0);
    reverse(m.begin(), m.end());
    cout << m.size() - z << endl;
    for(auto&i:m) {
        if(i != 0) cout << (i * pow(10, --cnt)) << " ";
        else --cnt;
    }
    cout << endl; 
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}