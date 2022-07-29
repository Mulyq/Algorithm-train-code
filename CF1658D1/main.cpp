#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> a(r + 1);
    for(int i = 0 ; i <= r; i ++) {
        cin >> a[i];
    }
    int res = 0;
    for(int i = 30; i >= 0 ; i --) {
        int cnt = 0;
        for(int j = 0; j <= r; j ++) {
            if(a[j] & (1 << i)) {
                cnt ++;
            }
            // a[j] >>= 1;
        }
        res <<= 1;
        if(cnt > ((r + 1) >> 1)) {
            res += 1;
        }
    }
    cout << res << "\n";
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