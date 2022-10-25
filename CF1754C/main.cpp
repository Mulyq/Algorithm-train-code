#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), vis(n);
    vector<int> p1, p2;
    vector<PII> res;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] == 1) p1.push_back(i);
        else if(a[i] == -1) p2.push_back(i);
    }
    if(p1.size() == p2.size()) {
        cout << n << '\n';
        for(int i = 1; i <= n; i ++) {
            cout << i << ' ' << i << '\n';
        }
    } else if((p1.size() + p2.size()) % 2 == 1) {
        cout << "-1\n";
    } else if(p1.size() > p2.size()) {
        bool ok = 0;
        for(int j = 0; j < p1.size(); j ++) {
            if(p1[j] > 0 && !vis[p1[j]] && !vis[p1[j] - 1]) {
                res.push_back({p1[j] - 1, p1[j]});
                vis[p1[j]] = vis[p1[j] - 1] = 1;
            }
            if(p1.size() - res.size() == p2.size() + res.size()) {
                ok = 1;
                break;
            }
        }
        if(ok) {
            for(int i = 0; i < n; i ++) {
                if(!vis[i]) {
                    res.push_back({i, i});
                }
            }
            sort(res.begin(), res.end());
            cout << res.size() << '\n';
            for(auto [l, r] : res) {
                cout << l + 1 << ' ' << r + 1 << '\n';
            }
        } else {
            cout << "-1\n";
        }
    } else if(p1.size() < p2.size()) {
        bool ok = 0;
        for(int j = 0; j < p2.size(); j ++) {
            if(p2[j] > 0 && !vis[p2[j]] && !vis[p2[j] - 1]) {
                res.push_back({p2[j] - 1, p2[j]});
                vis[p2[j]] = vis[p2[j] - 1] = 1;
            }
            if(p2.size() - res.size() == p1.size() + res.size()) {
                ok = 1;
                break;
            }
        }
        if(ok) {
            for(int i = 0; i < n; i ++) {
                if(!vis[i]) {
                    res.push_back({i, i});
                }
            }
            sort(res.begin(), res.end());
            cout << res.size() << '\n';
            for(auto [l, r] : res) {
                cout << l + 1 << ' ' << r + 1 << '\n';
            }
        } else {
            cout << "-1\n";
        }
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