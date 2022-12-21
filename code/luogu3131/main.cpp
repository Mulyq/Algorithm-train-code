#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        int temp;
        cin >> temp;
        a[i] = temp % 7;
    }
    for(int i = 1; i <= n; i ++) {
        a[i] = (a[i] + a[i - 1]) % 7;
    }
    int l[7], r[7];
    memset(l, -1,sizeof l);
    memset(r, -1,sizeof r);
    for(int i = 0; i <= n; i ++) {
        if(l[a[i]] == - 1) {
            l[a[i]] = i;
        }
    }
    for(int i = n; i >= 0; i --) {
        if(r[a[i]] == - 1) {
            r[a[i]] = i;
        }
    }
    int res = 0;
    for(int i = 0; i < 7; i ++) {
        if(l[i] != - 1 && r[i] != - 1)
            res = max(res, r[i] - l[i]);
    }
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}