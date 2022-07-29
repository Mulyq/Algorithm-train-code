#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].first;
        a[i].second = i  + 1;
    }
    sort(a.begin(), a.end());
    cout << a[0].second << ' ' << a[n - 1].second << '\n';
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