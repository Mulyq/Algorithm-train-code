#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    struct tt {
        vector<int> v;
        tt() {
            v.resize(k);
        }
        bool operator< (const tt &a) const{
            for(int i = 0; i < k; i ++) {
                if(v[i] != a.v[i]) {
                    return v[i] < a.v[i];
                }
            }
            return 0;
        }
    };
    set<tt> S;
    vector<tt> a(n);
    ll res = 0;
    for(int i = 0; i < n; i ++) {
        
        for(int j = 0; j < k; j ++) {
            cin >> a[i].v[j];
        }
        S.insert(a[i]);
    }
    for(int i = 0; i < n; i ++) {
        int c = 0;
        for(int j = 0; j < n; j ++) if(i != j) {
            tt fid;
            for(int t = 0; t < k; t ++) {
                if(a[i].v[t] == a[j].v[t]) {
                    fid.v[t] = a[i].v[t];
                } else {
                    fid.v[t] = 3 - a[j].v[t] - a[i].v[t];
                }
            }
            if(S.find(fid) != S.end()) c ++;
        }
        c /= 2;
        if(c >= 2) {
            res += 1ll * c * (c - 1) / 2;
        }
    }
    cout << res << '\n';
}