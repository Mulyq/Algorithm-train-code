#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    int k = n;
    vector<int> a;
    while(n) {
        a.push_back(n % 10);
        n /= 10;
    }
    sort(a.begin(), a.end());
    if(a.size() == 2) {
        if(k / 10 == a[0]) {
            cout << a[1];
        } else {
            cout << a[0];
        }
    } else {
        cout << a[0];
    }
    cout << '\n';
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