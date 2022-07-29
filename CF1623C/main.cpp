#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
vector<int> a;
bool check(int m) {
    vector<int> b = a;
    for(int i = b.size() - 1; i >= 2; i --) {
        if(b[i] < m) return 0;
        int d = min(a[i], b[i] - m) / 3;
        b[i - 1] += d;
        b[i - 2] += 2 * d;
    }
    return b[0] >= m && b[1] >= m;
}
void solve() {
    int n;
    cin >> n;
    a.resize(n);
    int l = INF, r = INF;

    for(int i = 0; i < n;i ++) {
        cin >> a[i];
        l = min(l, a[i]);
    }
    while(l < r) {
        int m = l + r + 1 >> 1;
        if(check(m)) l = m;
        else r = m - 1;
    }
    cout << l << '\n';
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