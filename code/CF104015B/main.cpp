#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int G[2][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < n; j ++) {
            char x;
            cin >> x;
            G[i][j] = x - '0';
        }
    }
    for(int i = 0; i < n; i ++) {
        if(G[0][i] == G[1][i] && G[0][i] == 1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}