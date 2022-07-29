#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            int t = 0;
            t = max(abs(1 - i) + abs(1 - j), t);
            t = max(abs(n - i) + abs(m - j), t);
            t = max(abs(1 - i) + abs(m - j), t);
            t = max(abs(n - i) + abs(1 - j), t);
            a.push_back(t);
        }
    }
    sort(a.begin(),a.end());
    for(auto i : a) {
        cout << i << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T ;
    while ( T--) {
        solve();
    }
    return 0;
}