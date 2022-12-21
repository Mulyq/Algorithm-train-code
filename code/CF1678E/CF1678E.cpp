#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 2e5 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), f(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
        f[b[i]] = i;
    }
    vector<vector<int>> e;
    vector<bool> ok(n + 1);
    ll res = 0;
    for(int i = 1; i <= n; i ++) {
        int ne = f[a[i]];
        if(!ok[i]) {
            vector<int> temp;
            temp.push_back(i);
            while(a[ne] != a[i]) {
                ok[ne] = 1;
                temp.push_back(ne); 
                ne = f[a[ne]];
            }
            e.push_back(temp);
        }
        ok[i] = 1;
    }
    int l = 1, r = n;
    vector<int> soc(n + 1);
    vector<int> temp;
    for(auto x : e) {
        if(x.size() % 2 == 0) {
            for(int i = 0; i < x.size(); i += 2) {
                soc[a[x[i]]] = r --,
                soc[a[x[i + 1]]] = l ++;
            }
        } else {
            for(int i = 0; i < x.size(); i ++) {
                if(i == x.size() / 2) {
                    continue;
                }
                if(i < x.size() / 2) {
                    if(i % 2 == 0)
                        soc[a[x[i]]] = r --;
                    else 
                        soc[a[x[i]]] = l ++;
                } else {
                    if(i % 2 == 1)
                        soc[a[x[i]]] = r --;
                    else 
                        soc[a[x[i]]] = l ++;
                }
            }
            temp.push_back(x[x.size() / 2]);
        }
    }
    for(auto x : temp) {
        soc[a[x]] = l ++;
    }
    for(int i = 1; i <= n; i ++) {
        // cout << soc[a[i]] << ' ';
        res += abs(soc[a[i]] - soc[b[i]]);
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