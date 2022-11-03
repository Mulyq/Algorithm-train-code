#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> vis(k + 1);
    int ne = k, siz = 0;
    vector<int> a(k);
    for(int i = 0; i < k; i ++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < k; i ++) {
        int x = a[i];
        vis[x] = 1;
        siz ++;
        while(x > 0 && vis[ne]) {
            ne --;
            siz --;
        }
        if(siz > n * m - 3) {
            cout << "TIDAK\n";
            return ;
        }
    }
    cout << "YA\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}