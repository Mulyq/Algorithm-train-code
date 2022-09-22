#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
bool cmp (int a, int b) {
    return a > b;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    if(n == 1) {    
        cout << "T\n";
        return;
    }
    sort(a.begin(), a.end(), cmp);
    while(a.size() > 2) {
        a[0] --, a[1] --;
        sort(a.begin(), a.end(), cmp);
        while(a.back() == 0) a.pop_back();
    }
    if(a.size() == 2 && a[0] == a[1] ) cout << "HL\n";
    else cout << "T\n";
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