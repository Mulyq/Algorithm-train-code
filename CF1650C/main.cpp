#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
struct node {
    int x, w, idx;
};
bool cmp1(node a, node b) {
    return a.w < b.w;
}
bool cmp2(node a, node b) {
    return a.x < b.x;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<node> a(m);
    for(int i = 0; i < m; i ++) {
        cin >> a[i].x >> a[i].w;
        a[i].idx = i + 1;
    }
    sort(a.begin(), a.end(), cmp1);
    vector<node> res;
    ll sum  = 0;
    for(int i = 0; i < 2 * n; i ++) {
        res.push_back(a[i]);
        sum += a[i].w;
    }
    sort(res.begin(), res.end(), cmp2);
    cout << sum << '\n';
    for(int i = 0, j = res.size() - 1; i < j; i ++, j --) {
        cout << res[i].idx << ' ' << res[j].idx << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}