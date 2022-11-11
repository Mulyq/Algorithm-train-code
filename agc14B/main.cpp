#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a --, b -- ;
        deg[a] ++, deg[b] ++;
    }
    for(int i = 0; i < n; i ++) {
        if(deg[i] % 2) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}