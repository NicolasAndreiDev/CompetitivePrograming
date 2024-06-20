#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 998244353
#define INF 0x3f3f3f3f

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, int> ii;
typedef tuple<int, int, int> tiii;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B) {
    vector<vector<ll>> result(2, vector<ll>(2));
    for(int i=0;i<2;++i) {
        for(int j=0;j<2;++j) {
            for(int k=0;k<2;++k) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % (MOD - 1);
            }
        }
    }
    return result;
}

vector<vector<ll>> fastexpmatriz(vector<vector<ll>> A, ll n) {
    if(n == 1) return A;
        vector<vector<ll>> result = fastexpmatriz(A, n / 2);
        result = multiply(result, result);
    if(n % 2 == 1) {
        vector<vector<ll>> temp = {{1, 1}, {1, 0}};
        result = multiply(result, temp);
    }

    return result;
}

ll fib(ll n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    vector<vector<ll>> base = {{1, 1}, {1, 0}};
    vector<vector<ll>> result = fastexpmatriz(base, n - 1);
    return result[0][0];
}

ll fastexp(ll b, ll e) {
    if(e == 0) return 1;
    if(e % 2 == 0) return fastexp(b*b % MOD, e/2);
    return b * fastexp(b, e-1) % MOD;
}

void solve() {
    ll n; cin >> n;
    cout << fastexp(2, fib(n)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 0;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}