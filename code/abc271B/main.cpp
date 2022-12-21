#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i ++) {
        int c;
        cin >> c;
        a[i].resize(c);
        for(int j = 0; j < c; j ++) {
            cin >> a[i][j];
        }
    }
    while(q --) {
        int x, y;
        cin >> x >> y;
        x--, y --;
        cout << a[x][y] << '\n';
    }
}