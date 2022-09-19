#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int res = 0;
    vector<int> c(n + 1);
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        if(x > y) c[y] ++;
        else c[x] ++;
    }
    for(int i = 1; i <= n; i ++) {
        if(!c[i]) {
            res ++;
        }
    }
    int q;
    cin >> q;
    while(q --) {
        int op, x, y;
        cin >> op;
        if(op == 1) {
            cin >> x >> y;
            if(x > y) {
                swap(x, y);
            }
            if(c[x] == 0) res --;
            c[x] ++;
        } else if(op == 2) {
            cin >> x >> y;
            if(x > y) {
                swap(x, y);
            } 
            c[x] --;
            if(c[x] == 0) res ++;
        } else {
            cout << res << '\n';
        }
    }
}