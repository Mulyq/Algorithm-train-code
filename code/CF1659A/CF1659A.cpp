#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, r, b;
    cin >> n >> r >> b;
    int k = r % (b + 1);
    int cnt = r / (b + 1);
    for(int i = 0; i <= b; i ++) {
        for(int j = 0; j < cnt; j ++) {
            cout << 'R';
        }
        if(k > 0) {
            cout << 'R';
            k --;
        }
        if(i != b)
            cout << 'B';
    }
    cout << '\n';
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