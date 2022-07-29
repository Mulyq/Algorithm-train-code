#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1);
    vector<int> pos;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '0') {
            a[i] ++;
        } else {
            pos.push_back(i);
        }
        if(i) {
            a[i] += a[i - 1];
        }
    }
    int l = -1, r = n;
    int one = pos.size();
    if(one <= 1) {
        cout << "0\n";
        return ;
    }
    while(r - l > 1) {
        int m = l + r >> 1;
        int c = INF;
        for(int i = 0; i < one; i ++) {
            int j = i + one - m - 1;
            if(j <= i) {
                c = 0;
                break;
            }
            if(j >= one) break;
            c = min(c, a[pos[j]] - (a[pos[i]]));
        }
        if(c <= m) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';

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