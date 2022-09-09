#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    while(l < r && s[l] == s[r]) {
        l ++, r --;
    }
    for(int i = l; i <= r; i += 2) {
        if(s[i] != s[i + 1]) {
            cout << "Alice\n";
            return ;
        }
    }
    cout << "Draw\n";
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