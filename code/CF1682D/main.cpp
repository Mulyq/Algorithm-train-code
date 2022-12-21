#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') cnt1 ++;
        else cnt0 ++;
    }
    if(cnt1 % 2 || ! cnt1) {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
    if(cnt1 == n) {
        for(int i = 2; i <= n; i ++) {
            cout << "1 " << i << '\n';
        }
    } else {
        vector<PII> res;
        int f = 0;
        while(s[f] != '1' || s[(f + 1) % n] != '0') {
            f ++;
        }
        (f += 1) %= n;
        int r = f;
        for(int i = 0; i < cnt1; i ++) {
            vector<int> temp;
            f = (f + 1) % n;
            temp.push_back(f);
            while(s[f] != '1') {
                f = (f + 1) % n;
                temp.push_back(f);
            }
            for(int j = 0; j < temp.size(); j ++) {
                if(!j) res.push_back({r, temp[j]});
                else {
                    res.push_back({temp[j], temp[j - 1]});
                }
            }
        }
        for(auto [x, y] : res) {
            cout << x + 1 << ' ' << y + 1 << '\n';
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