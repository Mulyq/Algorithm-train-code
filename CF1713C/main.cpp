#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    int k = n - 1;
    vector<int> res(n);
    while(k) {
        int t = sqrt(k);
        if(t * t == k) {
            for(int i = k; i >= 0; i --) {
                res[k - i] = i;
            }
            k = 0;
        } else {
                t = sqrt(k);
                int w = (t + 1) * (t + 1) - k;
                for(int i = k, z = w; i >= 0 && z <= k; i --) {
                    res[i] = z ++;
                }
                k = w - 1;
            }
    }
    for(int v : res) {
        cout << v << ' ';
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