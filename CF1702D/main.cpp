#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    string s;
    int k;
    cin >> s >> k;
    vector<int> a(26);
    int all = 0;
    for(int i = 0; i < s.size(); i ++) {
        a[s[i] - 'a'] ++;
        all += s[i] - 'a' + 1;
    }
    for(int i = 25; i >= 0 && all > k; i --) {
        if(all - (i + 1) * a[i] < k) {
            a[i] -= (all - k + i) / (i + 1);
            break;
        } else {
            all -= (i + 1) * a[i];
            a[i] = 0;
        }
    }
    for(auto x : s) {
        if(a[x - 'a']) {
            cout << x;
            a[x - 'a'] --;
        }
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