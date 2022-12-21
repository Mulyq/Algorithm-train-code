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
    int n, res = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;  i < n;i ++) {
        cin >> a[i];
    }
    int len = 0;
    for(int i = n - 1; i >= 0;) {
        if(a[n - 1] == a[i]) {
            len ++;
            i --;
        }
        else {
            res ++;
            i -= len;
            len *= 2;
        }
    }
    cout << res << '\n';
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