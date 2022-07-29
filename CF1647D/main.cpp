#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int x, d;
    cin >> x >> d;
    int cnt = 0;
    for(int i = d; i <= x / i; i += d) {
        if(x % i != 0) continue;
        int a = i, b = x / i;
        bool ok = 1;
        for(int j = d; j <= a / j; j += d) {
            if(a % j == 0) {
                ok = 0;
            }
        }
        for(int j = d; j <= b / j; j += d) {
            if(b % j == 0) {
                ok = 0;
            }
        }
        if(ok) {
            cnt ++;
        }
    }
    if(cnt) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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