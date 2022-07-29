#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e5 + 10;

void solve() {
    PII n[4];
    int L = INF, R = -INF;
    for(int i = 1; i <= 3; i ++) {
        cin >> n[i].first >> n[i].second;
        L = min(L, n[i].first);
        R = max(R, n[i].first);
    }
    sort(n + 1, n + 4, [&] (const PII & a, const PII & b) {
        return a.second < b.second;
    });
    vector<pair<PII, PII>> res;
    res.push_back({{L, n[2].second}, {R, n[2].second}});
    if(n[1].second != n[2].second) {
        res.push_back({n[1], {n[1].first, n[2].second}});
    }
    if(n[3].second != n[2].second) {
        res.push_back({n[3], {n[3].first, n[2].second}});
    }
    cout << res.size() << '\n';
    for(auto x : res) {
        cout << x.first.first << ' ' << x.first.second << ' ' << x.second.first << ' ' << x.second.second << '\n';

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}