#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
vector<PII> res;
int n;
void solve() {
    cin >> n;
    vector<int> a(n), b, c;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    while(a.size()) {
        if(c.empty() || a.back() < c.back()) {
            c.push_back(a.back());
            a.pop_back();
            res.push_back({1, 3});
        } else {
            b.push_back(a.back());
            a.pop_back();
            res.push_back({1, 2});
            while(c.size() && c.back() < b.back()) {
                a.push_back(c.back());
                c.pop_back();
                res.push_back({3, 1});
            }
            c.push_back(b.back());
            b.pop_back();
            res.push_back({2, 3});
        }
    }
    cout << res.size() << '\n';
    for(auto &[x, y] : res) {
        cout << x << ' ' << y << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
}