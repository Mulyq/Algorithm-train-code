#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    string s;
    cin >> s;
    int i = 0;
    int a = 0, b = 0;
    while(s[i] != '+') {
        a = a * 10 + s[i] - '0';
        i ++;
    }
    i ++;
    while(i < s.size()) {
        b = b * 10 + s[i] - '0';
        i ++;
    }
    cout << a + b << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}