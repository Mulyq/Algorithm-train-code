#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f ,mod = 998244353;

void solve() {
    int n;
    cin >> n;
    if(n % 2 == 1) {
        cout << "0\n";
    } else {
        ll res = 1;
        for(int i = 1; i <= (n >> 1); i ++) {
            res = (res * i) % mod;
        }
        res = (res * res) % mod;
        cout << res  << '\n';
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