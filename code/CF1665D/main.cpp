#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int ask(int a, int b) {
    cout << "?" << ' ' << a << ' ' << b << '\n';
    int x; 
    cin >> x;
    return x;
}
void solve() {
    int res = 0;
    for(int i = 0; i < 30; i ++) {
        int r = ask((1 << i) - res, (1 << i) + (1 << (i + 1)) - res);
        if(r == (1 << (i + 1))) res += (1 << i);
    }
    cout << "! " << res << '\n';
}
int main() {
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}