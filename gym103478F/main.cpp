#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for(int i = 0; i < 2 * n; i ++) {
        cin >> a[i];
    }
    int res = 0;
    for(int i = 1; i < 2 * n; i += 2) {
        if(a[i] < a[i - 1]) {
            if(i + 1 < 2 * n && a[i + 1] >= a[i - 1]) {
                swap(a[i], a[i + 1]);
                res ++;
            } else {
                swap(a[i], a[i - 1]);
                res ++;
            }
        }
    }
    cout << res << '\n';
}