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
    ll a, s;
    cin >> a >> s;
    ll x = s - a;
    if(x < 0 || x < a) {
        cout << "No\n";
        return ;
    }
    while(x) {
        if((x & 1) == 0 && (a & 1) == 1) {
            cout << "No\n";
            return;
        }
        x >>= 1, a >>= 1;
    }
    cout << "Yes\n";
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