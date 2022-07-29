#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
void solve() {
    string s;
    cin >> s;
    set<char> S;
    vector<int> pos(30, -1);
    int n = s.size();
    for(int i = 0; i < n; i ++) {
        S.insert(s[i]);
    }
    for(int i = 0; i < n; i ++) {
        if(pos[s[i] - 'a'] != -1) {
            set<int> temp;
            for(int j = pos[s[i] - 'a']; j < i; j ++) {
                temp.insert(s[j]);
            }
            if(temp.size() != S.size()) {
                cout << "NO\n";
                return;
            }
        }
        pos[s[i] - 'a'] = i;
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