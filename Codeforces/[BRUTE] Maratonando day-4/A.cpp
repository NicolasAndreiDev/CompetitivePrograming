#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, m, x; cin >> n >> m >> x;
    stack<int> s; s.push(x);

    while(m--) {
        int p; cin >> p;
        char op; cin >> op;
        
        set<int, greater<int>> val;
        int qtd = s.size();
        while(qtd--) {
            int x = s.top();
            if(op == '?') {
                int v = (x + p) % n == 0 ? n : (x + p) % n;
                val.insert(v);
                int v2 = (x - p + n) % n == 0 ? n : (x - p + n) % n;
                val.insert(v2);
            } else if(op == '0') {
                int v = (x + p) % n == 0 ? n : (x + p) % n;
                val.insert(v);
            } else {
                int v2 = (x - p + n) % n == 0 ? n : (x - p + n) % n;
                val.insert(v2);
            }
            s.pop();
        }

        for(auto v:val) s.push(v);
        val.clear();
    }

    cout << s.size() << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
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