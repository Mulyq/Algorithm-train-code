#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    if(a[0] != b[0] || a[n - 1] != b[n - 1]) {
        cout << "-1\n";
        return ;
    }
    vector<PII> posa, posb;
    for(int i = 0; i < n; i ++) {
        if(a[i] == '1') {
            int r = i;
            while(a[r] == '1') r ++;
            posa.push_back({i, r - 1});
            i = r - 1;
        }
    }
    for(int i = 0; i < n; i ++) {
        if(b[i] == '1') {
            int r = i;
            while(b[r] == '1') r ++;
            posb.push_back({i, r - 1});
            i = r - 1;
        }
    }
    if(posa.size() != posb.size()) {
        cout << "-1 \n";
        return ;
    }
    ll res = 0;
    for(int i = 0; i < posa.size(); i ++) {
        int al = posa[i].first, ar = posa[i].second;
        int bl = posb[i].first, br = posb[i].second;
        if(ar < bl || br < al) {
            res += (ar - al) + (br - bl) + 2 * min(abs(bl - ar), abs(al - br));
        } else  {
            res += abs(br - ar) + abs(bl - al);
        }
    }
    cout << res << '\n';
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