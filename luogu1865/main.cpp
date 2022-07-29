#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
bool isprime(int x) {
    if(x <= 1) {
        return 0;
    }
    for(int i = 2; i <= x / i; i ++) {
        if(x % i == 0) {
            return 0;
        }
    }
    return 1;
}
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        if(l < 1 || r > m) {
            cout << "Crossing the line\n";
            continue;
        }
        int res = 0;
        for(int j = l; j <= r; j ++) {
            if(isprime(j)) {
                res ++;
            }
        }
        cout << res << '\n';
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}