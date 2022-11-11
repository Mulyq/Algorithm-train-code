#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<PII> query(m);
    for(auto &[l, r] : query) {
        cin >> l >> r;
    }
    sort(query.begin(), query.end());
    int res = 0;
    int L = query[0].first, R = query[0].second;
    for(int i = 1; i < m; i ++) {
        if(query[i].first != L) {
            if(query[i].first < R) {
                L = query[i].first;
                R = min(R, query[i].second);
            } else {
                L = query[i].first, R = query[i].second;
                res ++;
            }
        }
    }
    cout << res  + 1 << '\n';
}