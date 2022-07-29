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
#include <stack>
#include <queue>
#include <bitset>
#include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1,vector<int> (k + 1));
    int ev = 1, odd = 2;
    for(int i = 1; i <= n; i ++) {
        if(i % 2 == 1) {
            for(int j = 1; j <= k ;j ++) {
                a[i][j] = ev;
                ev += 2;
            }
        }
        else {
            for(int j = 1; j <= k ;j ++) {
                a[i][j] = odd;
                odd += 2;
            }
        }
    }
    if(a[n][k] != n * k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= k ;j ++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}