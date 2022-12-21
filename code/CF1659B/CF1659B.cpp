#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> res(n);
    if(k % 2 == 1) {
        k --;
        for(int i = 0; i < n; i ++) {
            if(s[i] == '1') {
                res[i] ++;
                for(int j = 0; j < n; j ++) {
                    if(j == i) continue;
                    if(s[j] == '1') s[j] = '0';
                    else s[j] = '1';
                }
                break;
            }
            if(i == n - 1) {
                res[n - 1] ++;
                for(int j = 0; j < n; j ++) {
                    if(j == i) continue;
                    if(s[j] == '1') s[j] = '0';
                    else s[j] = '1';
                }
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        if(k && s[i] == '0') {
            res[i] ++;
            s[i] = '1';
            k --;
        }
        if(i == n - 1) {
            res[i] += k;
            if(k % 2 == 1) {
                if(k && s[i] == '0') s[i] = '1';
                else if(k) s[i] = '0';
            }
        }
    }
    cout << s << '\n';
    for(auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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