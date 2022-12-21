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
    int a, b, res = INF;
    cin >> a >> b;
    if((a | b) == b) {
        cout << 1 << '\n';
        return;
    }
    res = b - a;
    int t = 0;
    for(int i = a; i < a + res; i ++) {
        if(i == b) {
            res = min(i - a, res);
        }
        else if((i | b) == b) {
            res = min(i - a + 1, res);
        }
    }
    for(int j = b;; j ++) {
        if((j | a) == j) {
            res = min(j - b + 1, res);
            break;
        }
    }
    cout << res <<'\n';
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