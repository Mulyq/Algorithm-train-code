#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 3e6 + 10;
vector<int> a(N);
struct BIT {
    int N;
    vector<int> c;
    BIT(int n) : N(n) {
        c.resize(N + 1);
    }
    void add(int x, int d) {
        a[x] += d;
        int temp = a[x];
        for(; x <= N; x += x & - x) {
            c[x] = max(temp, c[x]);
        }
    }
    int ask(int x) {
        int res = 0;
        for(; x > 0; x -= x & -x) {
            res = max(res, c[x]);
        }
        return res;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    for(int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r};
    }
    sort(a.begin(), a.end());
    BIT bit(N);
    vector<int> dp(N);
    for(int i = 0; i < n; i ++) {
        int l = a[i].first, r = a[i].second;
        int dt = max(dp[r], bit.ask(l - 1) + r - l + 1) - dp[r];
        dp[r] += dt;
        if(dt) bit.add(r, dt);
    }
    cout << bit.ask(N) << '\n';
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