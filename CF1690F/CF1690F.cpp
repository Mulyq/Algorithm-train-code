#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> p(n);
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
        p[i] --;
    }
    vector<bool> v(n);
    ll res = 1;
    for(int i = 0; i < n; i ++) {
        if(v[i]) continue;
        vector<int> temp;
        int nn = i;
        while(!v[nn]) {
            temp.push_back(nn);
            v[nn] = 1;
            nn = p[nn];
        }
        ll c = 0;
        string t = s;
        do {
            c ++;
            string tt = t;
            for(int x : temp) {
                t[p[x]] = tt[x];
            }
        } while(s != t);
        res = res * c / __gcd(res, c);
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