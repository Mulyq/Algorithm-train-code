#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int x, y;
    cin >> x >> y;
    if(x == 0 && y == 0) {
        cout << 0 << '\n';
    } else {
        int X = x * x, Y = y * y;
        int t = sqrt(X + Y);
        if(t * t == X  + Y) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}