#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> S;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        S.insert(a[i]);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i ++) {
        int w = k + a[i];
        if(S.find(w) != S.end()) {
            cout << "Yes\n";
            return;
        }
    }
    cout <<"No\n";
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