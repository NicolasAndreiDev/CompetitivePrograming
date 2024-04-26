#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;

int binarySearch(int n, int k) {
    int l = 1, r = 2*k;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(mid - mid / n >= k) r = mid - 1;
        else l = mid + 1;
    }

    return l;
}

void solve() {
    int n, k; cin >> n >> k;
    cout << binarySearch(n, k) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    int tc = 1;
    if(tc) {
        int t; cin >> t;
        while(t--) solve();
    } else solve();
}
