#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> G(n, vector<char> (n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> G[i][j];
        }
    }
    if(m & 1) {
        cout << "YES\n";
        cout << 1 << ' ';
        while(m) {
            cout << (m & 1) + 1 << ' ';
            m --;
        }
        cout << '\n';
        return ;
    } else {
        for(int i = 0; i < n; i ++) {
            for(int j = i + 1; j < n; j ++) {
                if(G[i][j] == G[j][i]) {
                    cout << "YES\n";
                    cout << i + 1 << ' ';
                    while(m) {
                        if(m & 1) cout << i + 1 << ' ';
                        else cout << j + 1 << ' ';
                        m --;
                    }
                    cout << '\n';
                    return ;
                } else if(m % 4 != 0) {
                    for(int k = j + 1; k < n; k ++) {
                        if(G[i][j] == G[j][k]) {
                            cout << "YES\n";
                            cout << i + 1 << ' ';
                            for(int c = 0; m ; m --, c ++) {
                                if(c % 4 == 0) cout << j + 1 << ' ';
                                else if(c % 4 == 1) cout << k  + 1 << ' ';
                                else if(c % 4 == 2) cout << j + 1 << ' ';
                                else cout << i + 1 << ' ';
                            }
                            cout << '\n';
                            return ;
                        }
                    }
                }
            }
        }
        cout << "NO\n";
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