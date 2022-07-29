#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 2e5 + 10;
struct BIT {
    int N;
    vector<int> c;
    BIT() {
        N = MAXN;
        c.resize(N);
    }
    void add(int x, int d) {
        for(; x <= N; x += x & -x) {
            c[x] += d;
        }
    }
    ll query(int x) {
        ll res = 0;
        for(; x; x -= x & - x) {
            res += c[x];
        } 
        return res;
    }
} bit[3];

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> pre(n + 1);
    vector<int> a(n + 1);
    for(int i = 0; i < n; i ++) {
        if(s[i] == '-') {
            a[i + 1] = 1;
        } else {
            a[i + 1] = -1;
        }
    }
    for(int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] + a[i];
    }
    vector<int> temp = pre;
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    for(int i = 0; i <= n; i ++) {
        pre[i] = lower_bound(temp.begin(), temp.end(), pre[i]) - temp.begin() + 1;
    }
    ll res = 0;
    for(int i = 0; i <= n; i ++) {
        res += bit[pre[i] % 3].query(pre[i]);
        bit[pre[i] % 3].add(pre[i], 1);
    }
    cout << res << '\n';
    for(int i = 0; i <= n; i ++) {
        bit[pre[i] % 3].add(pre[i], -1);
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