#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
struct BIT {
    int N;
    vector<int> c;
    BIT(int n) : N(n) {
        c.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int d) {
        for(;x <= N; x += lowbit(x)) {
            c[x] += d;
        }
    }
    int sum(int x) {
        int res = 0;
        for(;x ; x -= lowbit(x)) {
            res += c[x];
        }
        return res;
    }
    int sum(int x, int y) {
        return sum(y) - sum(x);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int cnt = b.size();
    for(int i = 0; i < n; i ++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }
    BIT bit(cnt + 1);
    ll res = 0;
    for(int i = 0; i < n; i ++) {
        // cout << bit.sum(a[i]) << ' ' << bit.sum(a[i], cnt) << '\n';
        res += min(bit.sum(a[i] - 1), bit.sum(a[i], cnt));
        bit.add(a[i], 1);
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}