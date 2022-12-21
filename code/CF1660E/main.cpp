#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    vector<vector<int>> a(n, vector<int> (n));
    for(int i = 0;i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            char x;
            cin >> x;
            a[i][j] = x - '0';
            cnt += x - '0';
        }
    }
    int mx = 0;
    for(int  i = 0; i < n; i ++) {
        int temp = 0;
        for(int j = 0; j < n; j ++) {
            temp += a[(i + j) % n][j];
        }
        mx = max(mx, temp);
    }

    int res = (n - mx) + (cnt - mx);
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