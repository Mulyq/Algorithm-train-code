#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(26);
    vector<int> tempres;
    for(int i = 0; i < 2 * n + 1; i ++) {
        string s;
        cin >> s;
        if(s.size() == 1) {
            tempres.push_back(s[0] - 'a');
        }
        for(int i = 0; i < s.size() ; i ++) {
            cnt[s[i] - 'a'] ++;
        }
    }
    sort(tempres.begin(),tempres.end());
    tempres.resize(unique(tempres.begin(), tempres.end()) - tempres.begin());
    for(int i = 0; i < tempres.size(); i ++) {
        if(cnt[tempres[i]] % 2 == 1) {
            char res = tempres[i] + 'a';
            cout << res << '\n'; 
        }
    }
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