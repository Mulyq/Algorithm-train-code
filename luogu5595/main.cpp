#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    string s;
    cin >> s;
    string x, y;
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == 'Z') {
            if(i == 0 || s[i - 1] == 'Z') {
                x += '0', y += '0';
            } else {
                cout << -1 << '\n';
                return ;
            }
        } else if(s[i] == 'X'){
            x += '1', y += '0';
        } else {
            x += '0', y += '1';
        }
    }
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    cout << x << '\n' << y << '\n';
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