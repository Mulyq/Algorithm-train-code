#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    for(int i = 0; i <= r; i ++) {
        if (s[i] == '1') l = i;
    }
    for(int i = s.size() - 1; i >= l; i --) {
        if(s[i] == '0') r = i;
    }
    cout << r - l + 1 << '\n';
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