#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
char G[10][10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    for(int i = 0; i < 10; i ++) {
        for(int j = 0; j < 10; j ++) {
            cin >> G[i][j];
        }
    }
    bool ok = 1;
    for(int i = 0; i < 10 && ok; i ++) {
        for(int j = 0; j < 10 && ok; j ++) {
            if(G[i][j] == '#') {
                a = i + 1, c = j + 1;
                ok = 0;
            }
        }
    }
    ok = 1;
    for(int i = 9; i >= 0 && ok; i --) {
        for(int j = 9; j >= 0 && ok; j --) {
            if(G[i][j] == '#') {
                b = i + 1, d = j + 1;
                ok = 0;
            }
        }
    }
    cout << a << ' ' << b << '\n';
    cout << c << ' ' << d << '\n';

}