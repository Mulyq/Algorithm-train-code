#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    if(s.size() == 1) {
        cout <<"NO\n";
        return ;
    }
    for(int i = 1; i < s.size() - 1; i ++) {
        if(s[i] != s[i - 1] && s[i] != s[i + 1]) {
            cout << "NO\n";
            return ;
        }
    }
    if(s[0] != s[1] || s[s.size() - 1] != s[s.size() - 2]) {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}