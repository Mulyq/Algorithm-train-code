#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int get(int x) {
    int res = 0;
    while(x) {
        x >>= 1;
        res ++;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector<vector<int>> v(32);
    for(int i = 1; i <= n; i ++) {
        v[get(a[i])].push_back(a[i]);
    }
    for(int i = 0; i < 32; i ++) {
        if(v[i].size() >= 3) {
            cout << 1 << '\n';
            return 0;
        }
    }
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        pre[i] = a[i] ^ pre[i - 1];
    }
    int res = INF;
    for(int l = 1; l <= n; l ++) {
        for(int r = l + 1; r <= n; r ++) {
            int x = pre[r] ^ pre[l - 1];
            for(int i = 1; i < l; i ++) {
                for(int j = i; j < l; j ++) {
                    int y = pre[j] ^ pre[i - 1];
                    if(y > x) {
                        res = min(res, r - l + j - i);
                    }
                }
            }
            for(int i = r + 1; i <= n; i ++) {
                for(int j = i; j <= n; j ++) {
                    int y = pre[j] ^ pre[i - 1];
                    if(x > y) {
                        res = min(res, r - l + j - i);
                    }
                }
            }
        }
    }
    if(res != INF) cout << res << '\n';
    else cout << "-1\n";
}