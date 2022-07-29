#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    int res = 0;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            char temp;
            cin >> temp;
            a[i][j] = temp - '0';
            res += a[i][j];
        }
    }
    if(a[0][0] == 1) {
        cout << -1 << '\n';
        return;
    }
    cout << res << '\n';
    for(int i = 0; i < n; i ++) {
        for(int j = m - 1; j >= 1; j --) {
            if(a[i][j] == 1) {
                cout << i + 1 << ' ' << j << ' ' << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    }
    for(int i = n - 1; i >= 1; i --) {
        if(a[i][0] == 1) {
            cout << i << ' ' << 1 << ' ' << i + 1 << ' ' << 1 << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}