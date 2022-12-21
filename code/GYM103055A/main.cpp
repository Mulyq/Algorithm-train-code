#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    ll a, b;
    b = a = 0;
    for(int i = 0; i < 5; i ++) {
        ll temp;
        cin >> temp;
        a += temp;
    }
    for(int i = 0; i < 5; i ++) {
        ll temp;
        cin >> temp;
        b += temp;
    }
    if(a < b) {
        cout << "Red\n";
    } else {
        cout << "Blue\n";
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