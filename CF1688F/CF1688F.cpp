#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e1 + 10;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[i] -= x;
    }
    for(int i = 1; i <= n; i ++) {
        a[i] += a[i - 1];
    }
    set<int> S;
    queue<int> q;
    vector<vector<int>> e(n + 1);
    for(int i = 0; i <= n; i ++) {
        if(a[i]) S.insert(i);
        else q.push(i);
    }
    for(int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        e[l - 1].push_back(r);
        e[r].push_back(l - 1);
    }
    while(q.size()) {
        int p = q.front();
        q.pop();
        for(auto v : e[p]) {
            if(S.find(v) == S.end()) {
                // q.push(p);
                if(v < p) swap(v, p);
                auto i = S.lower_bound(p), j = S.upper_bound(v);
                while(i != S.end() && i != j) {
                    q.push(*i);
                    S.erase(i ++);
                }
            }
        }
    }
    if(S.size()) cout << "NO\n";
    else cout << "YES\n";
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