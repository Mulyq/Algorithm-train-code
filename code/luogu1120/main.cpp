#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, all;
vector<int> a;
bool check(int xl, vector<int> &t) {
    int len = t.size();
    bool res = 0;
    if(xl == n) {
        return 1;
    }
    for(int i = 0; i < len; i ++) {
        t[i] -= a[xl];
        if(t[i] >= 0) {
            res |= check(xl + 1, t);
        }
        t[i] += a[xl];
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    int mx = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        all += a[i];
        mx = max(mx, a[i]);
    }
    sort(a.rbegin(), a.rend());
    for(int i = mx; i <= all; i ++) {
        if(all % i == 0) {
            if(all / i > 50) continue;
            vector<int> cnt(all / i, i);
            if(check(0, cnt)) {
                cout << i << '\n';
                break;
            }
        }
    }
}