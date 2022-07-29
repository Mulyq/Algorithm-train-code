#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    vector<int> a(7);
    for(int i = 1; i <= 6; i ++ ) {
        string s;
        cin >> s;
        if(s == "true") {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    }
    if(a[1] == a[3] && a[1] != a[2]) {
        bool ok = 1;
        for(int i = 1; i <= 3; i ++) {
            if(a[i] != a[i + 3]) {
                ok = 0;
            }
        }
        if(ok) {
            cout << 7 << '\n';
            return ;
        }
    }
    int cnt = 0;
    for(int i = 1;i <= 3; i ++) {
        cnt += a[i] ^ a[i + 3];
    }
    if(cnt == 0) {
        cout << 8 << '\n';
    } else {
        cout << 7 - cnt << '\n';
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