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
const int INF = 0x3f3f3f3f;

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    if(l == r && r != 1) {cout << "YES\n";return ;}
    if(l % 2 == 0 || r % 2 == 0)
        if(k >= (r - l + 1 >> 1)) cout << "YES\n";
        else cout << "NO\n";
    else 
        if(k >= (r - l + 2 >> 1)) cout << "YES\n";
        else cout << "NO\n";
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