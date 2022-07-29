#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') {
            cnt ++;
        }
    }
    if(cnt % 2 == 1 || s[0] == '0' || s.back() == '0') {
        cout << "NO\n";
        return;
    }
    string res1, res2;
    int f = 1;
    int k = 0;
    for(int i = 0 ; i < n; i ++) {
        if(s[i] == '1') {
            if(k < (cnt >> 1)) {
                res1 += '(';
                res2 += '(';
            } else {
                res1 += ')';
                res2 += ')';
            }
            k ++;
        } else {
            if(f) {
                res1 += '(';
                res2 += ')';
                f = 1 - f;
            } else {
                res2 += '(';
                res1 += ')';
                f = 1 - f;

            }
        }
    }
    cout << "YES\n" << res1 << '\n' << res2 << '\n';
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