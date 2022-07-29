#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    int c = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'b') c ++;
        if(t[i] == 'b') c --;
    }
    if(c) {
        cout << "NO\n";
        return ;
    }
    for(int i = 0, j = 0; i < n; i ++) {
        if(s[i] == 'b') {
            continue;
        }
        while(t[j] == 'b') {
            j ++;
        }
        if(s[i] != t[j]  || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j)) {
            cout << "NO\n";
            return;
        }
        j ++;
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