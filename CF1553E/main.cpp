#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
bool check(vector<int> a, int d) {
    int c = 0;
    for(int i = 0; i < n; i ++) {
        int t = (a[i] - i + n) % n;
        if((a[i] - i + n) % n != d) {
            int w = t - d;
            swap(a[i], a[(i + w + n) % n]);
            c ++;
        }
    }
    if(c > m) return 0;
    return 1;
}
void solve() {
    cin >> n >> m;
    vector<int> a(n), d(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] --;
        d[(a[i] - i + n) % n] ++;
    }
    vector<int> res;
    for(int i = 0; i < n; i ++) {
        if(d[i] >= n - 2 * m) {
            // vector<int> temp = a;
            if(check(a, i)) res.push_back((n - i) % n);
        }
    }
    cout << res.size() << ' ';
    sort(res.begin(), res.end());
    for(int v : res) {
        cout << v << ' ';
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
    return 0;
}