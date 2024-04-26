#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

map<int, string> m;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    string ans = "";
    for(int i=n-1;i>=0;i--) {
        string aux = "";
        if(s[i] == '0') {
            aux += s[i - 2];
            aux += s[i - 1];            
            aux += s[i];
            int aux2 = stoi(aux);
            ans += m[aux2];
            i-=2;
        } else {
            string aux3 = "";
            aux3 += s[i];
            int aux2 = stoi(aux3);
            ans += m[aux2];
        }
    } 

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        m[1] = 'a';
        int cnt = 2;
        for(int i=1;i<26;i++) {
            if(cnt >= 10) {
                m[cnt * 10] = ('a' + cnt - 1);
            } else{
                m[cnt] = ('a' + cnt - 1);
            }
            cnt++;
        }

        int t; cin >> t;
        while(t--) solve();
    } else solve();
}