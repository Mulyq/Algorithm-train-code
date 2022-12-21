#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n ; i ++) {
        cin >> a[i];
    }
    vector<int> t;
    int cnt = 0, tw = 0;
    int st = 0 , ed = n - 1;
    vector<pair<int,PII>> res;
    for(int i = 0; i <= n; i ++) {
        ed = i - 1;
        if(i == n || a[i] == 0 ) {
            if(cnt % 2 == 1) {
                int tww = tw;
                int cl = st, cr = ed;
                for(int j = 0; j < t.size(); j ++) {
                    cl ++;
                    if(t[j] < 0) {
                        if(t[j] == - 2) {
                            tww --;
                        }
                        break;
                    } else {
                        if(t[j] == 2) {
                            tww --;
                        }
                    }
                }
                res.push_back({tww, {cl, n - 1 - ed}});
                tww = tw;
                cl = st, cr = ed;
                for(int j = t.size() - 1; j >= 0; j --) {
                    cr --;
                    if(t[j] < 0) {
                        if(t[j] == -2) {
                            tww --;   
                        }
                        break;
                    } else {
                        if(t[j] == 2) {
                            tww --;
                        }
                    }
                }
                res.push_back({tww, {st, n - 1 - cr}});
            } else {
                res.push_back({tw, {st, n - 1 - ed}});
            }
            cnt = 0;
            tw = 0;
            st = i + 1;
            t = vector<int> ();
        } else {
            if(a[i] < 0) cnt ++;
            if(abs(a[i]) == 2) tw ++;
            t.push_back(a[i]);
        }
    }
    int id = 0;
    for(int i = 1; i < res.size() ; i ++) {
        if(res[i].first > res[id].first) {
            id = i;
        }
    }
    cout << res[id].second.first << ' ' << res[id].second.second << '\n';
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