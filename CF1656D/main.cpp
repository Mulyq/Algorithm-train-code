#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
void solve() {
    ll n;
    cin >> n;
    ll k = 1;
    while(n % 2 == 0) {
        n /= 2;
        k *= 2;
    }
    if(n == 1) {
        cout << "-1\n";
    } else {
        if(k - 1 >= (n >> 1)) {
            cout << n << "\n";
        } else if((n >> 1) >= k) {
            cout << k * 2 << "\n";
        } else {
            cout << "-1\n";
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