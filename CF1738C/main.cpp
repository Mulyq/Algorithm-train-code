#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        if(x % 2 == 0) even ++;
        else odd ++;
    }
    if((odd % 2 == 0 && odd % 4 != 0) || (odd % 2 == 1 && (odd - 1) % 4 == 0 && even % 2 == 0)) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
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