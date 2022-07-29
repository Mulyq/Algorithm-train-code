#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    for(int i = 0; i < n - 1; i ++) {
        if(s[i] == '0' && s[i + 1] == '0') {
            res += 2;
        } else if(s[i] == '0'){
            if(i + 2 < n && s[i + 2] != '1') {
                res += 1;
            }
        }
    }
    cout << res << '\n';
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