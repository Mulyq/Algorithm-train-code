#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e5 + 10;
void solve() {
    string s, t;
    cin >> s >> t;
    vector<int> cnt(50);
    for(int i = 0; i < t.size(); i ++) {
        cnt[t[i] - 'A'] ++;
    }
    for(int i = s.size() - 1, j = t.size() - 1; i >= 0; i --) {
        if(s[i] != t[j]) {
            if(cnt[s[i] - 'A'] > 0) {
                cout << "NO\n";
                return ;
            }
        } else {
            cnt[t[j] - 'A'] --;
            j --;
        }
        if(j == - 1) {
            cout << "YES\n";
            return ;
        }
    }
    cout << "NO\n";
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