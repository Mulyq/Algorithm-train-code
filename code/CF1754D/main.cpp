#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 5e5 + 10, mod = 998244353;
int c[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        c[t] ++;
    }
    for(int i = 1; i < x; i ++) {
        if(c[i] % (i + 1) == 0) {
            c[i + 1] += c[i] / (i + 1);
        } else {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}