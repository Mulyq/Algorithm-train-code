#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector<vector<int>> cnt1(n + 1, vector<int> (n + 1)), cnt2(n + 1, vector<int> (n + 1));
    for(int j = 1; j <= n; j ++) {
        for(int i = 1; i <= n; i ++) {
            if(a[i] < j) {
                cnt1[i][j] ++;
            }
        }
    }
    for(int j = 1; j <= n; j ++) {
        for(int i = 1; i <= n; i ++) {
            cnt1[i][j] += cnt1[i - 1][j];
        }
    }

    for(int j = 1; j <= n; j ++) {
        for(int i = n; i >= 1; i --) {
            if(a[i] < j) {
                cnt2[i][j] ++;
            }
        }
    }
    for(int j = 1; j <= n; j ++) {
        for(int i = n - 1; i >= 1; i --) {
            cnt2[i][j] += cnt2[i + 1][j];
        }
    }
    ll res = 0;
    for(int i = 1; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            int x = cnt1[i - 1][a[j]];
            int y = cnt2[j + 1][a[i]];
            res += x * y;
        }
    }
    cout << res << '\n';
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