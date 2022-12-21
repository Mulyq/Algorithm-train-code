#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    for(int i = 0 ;i  < n; i ++) {
        int s, t;
        cin >> s >> t;
        a[i] = {t, s};
    }
    sort(a.begin(), a.end());
    int res = 0;
    int st = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].second < st) {
            continue;
        }
        res ++;
        st = a[i].first;
    }
    cout << res <<'\n';
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