#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
string s;
void solve() {
    getline(cin, s);
    for(int i = 0; i < s.size(); i ++) {
        if(!i || s[i - 1] == ' ') {
            char x = s[i] + 'A' - 'a';
            cout << x;
        }
    }
    cout << '\n';
}
int main() {
    int _ = 1;
    cin >> _;
    getline(cin, s);
    while(_ --) {
        solve();
    }
    return 0;
}