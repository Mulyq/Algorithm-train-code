#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    string op;
    cin >> n >> op;
    int res = 1 + op.size();
    int R = 1, C = 1;
    PII fir = {0, 0};
    for(auto s : op) {
        if(s == 'D') R ++;
        else C ++;
        if(s != op[0] && fir.first == 0) {
            fir = {R, C};
        } 
    }
    int rR = n - R, rC = n - C;
    if(op[0] == 'D') {
        res += rR * C + rC * (n - fir.first + 1);
    } else {
        res += rC * R + rR * (n - fir.second + 1);
    }
    if(fir.first == 0) res = n;
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}