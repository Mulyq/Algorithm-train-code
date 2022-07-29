#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n;
    cin >> n;
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= (i >> 1) ;j ++) {
            f[j] += f[i];
        }
        f[i] ++;
    }
    cout << f[n] << '\n';
    return 0;
}