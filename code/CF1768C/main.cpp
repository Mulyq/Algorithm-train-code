#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), v(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        v[i] = i;
    }
    sort(v.begin(), v.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    vector<int> q(n), p(n);
    set<int> sp, sq;
    for(int i = 1; i <= n; i ++) {
        sq.insert(i);
        sp.insert(i);
    }
    for(int i = 0; i < n; i ++) {
        int id = v[i];
        int x = a[id];
        if(sq.find(x) != sq.end()) {
            q[id] = x;
            sq.erase(x);
            p[id] = *sp.lower_bound(1);
            sp.erase(p[id]);
        } else if(sp.find(x) != sp.end()) {
            p[id] = x;
            sp.erase(x);
            q[id] = *sq.lower_bound(1);
            sq.erase(q[id]);
        } else {
            cout << "NO\n";
            return;
        }
        if(max(p[id], q[id]) != a[id]) {
            cout << "NO\n";
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i ++) {
        cout << q[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i ++) {
        cout << p[i] << ' ';
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
}