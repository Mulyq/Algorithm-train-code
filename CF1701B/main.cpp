#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    cout << 2 << '\n';
    vector<int> res;
    vector<bool> vis(n + 1, 1);
    for(int f = 1; f <= n; f ++) {
        if(vis[f]) {
            for(int i = f; i <= n; i *= 2) {
                if(vis[i]) {
                    res.push_back(i);
                    vis[i] = 0;
                }
            }
            vis[f] = 0;
        }
    }
    for(int x : res) {
        cout << x << ' ';
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