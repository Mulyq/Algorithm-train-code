#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
void solve() {
    int n;
    cin >> n;
    vector<PII> segs(n);
    for(int i = 0; i < n;i ++) {
        cin >> segs[i].second;
    }
    for(int i = 0; i < n;i ++) {
        cin >> segs[i].first;
        segs[i].first = segs[i].second - segs[i].first + 1;
    }
    sort(segs.begin(), segs.end());
    int be = segs[0].first, en = segs[0].second;
    vector<PII> rec;
    for(int i = 1; i < n; i ++) {
        if(segs[i].first > en) {
            rec.push_back({be, en});
            be = segs[i].first;
            en = segs[i].second;
        } else {
            en = max(en, segs[i].second);
        }
    }
    rec.push_back({be, en});
    ll res = 0;
    for(auto x : rec) {
        ll l = x.first, r = x.second;
        r -= l - 1, l = 1;
        res += (l + r) * r / 2;
    }
    cout << res << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while( T --) {
        solve();
    }
    return 0;
}