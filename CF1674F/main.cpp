#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
struct BIT {
    int N;
    vector<int> d;
    BIT(int n) : N(n) {
        d.resize(N + 1);
    }
    void add(int x, int c) {
        for(x; x <= N; x += x & -x) {
            d[x] += c;
        }
    }
    int ask(int x) {
        int res = 0;
        for(;x ; x -= x & -x ) {
            res += d[x];
        }
        return res;
    }
};
char desk[1010][1010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    BIT bitx(m + 1);
    vector<BIT> bity(m + 1, n + 1);
    int all = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> desk[i][j];
            if(desk[i][j] == '*') {
                all ++;
                bity[j].add(i, 1);
            }
        }
    }
    for(int i = 1; i <= m; i ++) {
        bitx.add(i, bity[i].ask(n));
    }
    
    while(q --) {
        int x, y;
        cin >> x >> y;
        if(desk[x][y] == '.') {
            all ++;
            bity[y].add(x, 1);
            bitx.add(y, 1);
            desk[x][y] = '*';
        } else {
            all --;
            bity[y].add(x, -1);
            bitx.add(y, -1);
            desk[x][y] = '.';
        }
        int qx = all / n, qy = all % n;
        int res = 0;
        res += bitx.ask(qx);
        res += bity[qx + 1].ask(qy);
        cout << all - res << '\n';
    }
    return 0;
}