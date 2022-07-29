#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
struct c {
    ll d, s, t;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> rr(n);
    vector<c> ord(m);
    for(int i = 0; i < n; i ++) cin >> rr[i];
    for(auto &[d, s, t] : ord) {
        cin >> d >> s >> t;
    }
    int l = 0, r = m - 1;
    while(l <= r) {
        int mid = l + r >> 1;
        vector<ll> day(n + 1);
        for(int i = 0; i < mid; i ++) {
            int d = ord[i].d, s = ord[i].s, t = ord[i].t;
            day[s - 1] += d, day[t] -= d;
        }
        bool ok = 1;
        for(int i = 0; i < n; i ++) {
            if(i) {
                day[i] += day[i - 1];
            }
            if(day[i] > rr[i]) {
                ok = 0;
            }
        }
        if(ok) l = mid + 1;
        else r = mid - 1;
    }
    if(l == m) cout << 0 << '\n';
    else cout << - 1 << '\n' << r + 1;
    return 0;
}