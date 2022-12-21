#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), res(n, 0);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    set<int> s;
    for(int i = 0; i < n; i ++) {
        s.insert(i);
    }
    for(int i = 0; i < n - 1; i ++) {
        int x = a[i] - a[i + 1];
        if(x > 0) {
            auto it = s.lower_bound(x);
            res[*it] = i + 1;
            s.erase(it);
        }
    }
    for(int i : res) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}