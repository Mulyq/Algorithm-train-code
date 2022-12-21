#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    ll s, res = 1e12 + 100;
    cin >> n >> m >> s;
    vector<PII> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<PII> egs(m);
    for(int i = 0; i < m; i ++) {
        cin >> egs[i].first >> egs[i].second;
    }
    int l = 0, r = 1e6 + 1;
    while(l < r) {
        ll mid = l + r >> 1;
        vector<PII> b;
        for(int i = 0; i <= n; i ++) {
            b.push_back(a[i]);
        }
        for(int i = 1; i <= n; i ++) {
            if(b[i].first < mid) {
                b[i].first = 0;
                b[i].second = 0;
            } else {
                b[i].first = 1;
            }
        }
        for(int i = 1; i <= n; i ++) {
            b[i].first += b[i - 1].first;
            b[i].second += b[i - 1].second;
        }
        ll y = 0;
        for(int i = 0; i < m; i ++) {
            int hh = egs[i].first, tt = egs[i].second;
            ll sw = b[tt].first - b[hh - 1].first;
            ll allv = b[tt].second - b[hh - 1].second;
            y += sw * allv;
        }
        if(y <= s) r = mid;
        else l = mid + 1;
        res = min(res, abs(s - y));
    }
    cout << res;
    return 0;
}