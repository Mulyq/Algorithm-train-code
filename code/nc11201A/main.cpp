#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define int ll
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
int get(int x) {
    int res = 0;
    while(x) {
        x >>= 1;
        res ++;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(50);
    set<int> S;
    vector<int> ex;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if(S.find(x) == S.end()) {
            S.insert(x);
            a[get(x)] ++;
        } else {
            ex.push_back(x);
        }
    }
    int res = 0;
    for(int i = 0; i < 32; i ++) {
        res += a[i] * (a[i] - 1) / 2;
    }
    ex.resize(unique(ex.begin(), ex.end()) - ex.begin());
    res += ex.size();
    cout << res << '\n';
}