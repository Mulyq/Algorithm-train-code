#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    string c;
    for(int i = 0; i < b.size() - 1; i ++) {
        c.push_back(a.back());
        a.pop_back();
    }
    string d = b;
    d.erase(d.begin());
    reverse(c.begin(), c.end());
    bool ok[2] = {0, 0};
    for(int i = 0; i < a.size(); i ++) {
        ok[a[i] - '0'] = 1;
    }
    if(c == d) {
        if(ok[b[0] - '0']) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }
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