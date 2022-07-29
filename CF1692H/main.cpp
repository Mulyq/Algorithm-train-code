#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) {
        cin >> i;
    }
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    int nn = temp.size();
    vector<int> b = a;
    for(int i = 0; i < n; i ++) {
        b[i] = lower_bound(temp.begin(), temp.end(), b[i]) - temp.begin();
    }
    vector<vector<int>> e(nn);
    for(int i = 0; i < n; i ++) {
        int x = b[i];
        e[x].push_back(i);
    }
    PII res = {0, 0};
    int maxx = 1;
    for(int i = 0; i < nn; i ++) {
        ll mm = 1;
        int l = e[i][0], r = e[i][0];
        for(int j = 1; j < e[i].size(); j ++) {
            ll t = e[i][j] - e[i][j - 1];
            t = 2 - t;
            mm = mm + t;
            if(mm <= 0) {
                mm = 1;
                l = r = e[i][j];
            } else {
                r = e[i][j];
            }
            if(maxx < mm) {
                res = {l, r};
                maxx = mm;
            }
        }
    }
    cout << a[res.first] << ' ' << res.first + 1 << ' ' << res.second + 1 << '\n';
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