#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    struct node {
        int s, a;
        const bool operator< (const node &b) const {
            return a > b.a;
        }
    };
    vector<node> v(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> v[i].s;
    }
    for(int i = 1; i <= n; i ++) {
        cin >> v[i].a;
    }
    sort(v.begin() + 1, v.end());
    vector<int> sum(n + 1), sh(n + 1), st(n + 1);
    for(int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1] + v[i].a;
    }
    for(int i = 1; i <= n; i ++) {
        sh[i] = max(sh[i - 1], 2 * v[i].s);
    }
    for(int i = n; i >= 1; i --) {
        if(i == n) {
            st[i] = v[i].a + 2 * v[i].s;
        } else {
            st[i] = max(st[i + 1], v[i].a + 2 * v[i].s);
        }
    }
    for(int i = 1; i <= n; i ++) {
        int res = max(sum[i] + sh[i], sum[i - 1] + st[i]);
        cout << res << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}