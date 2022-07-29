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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];
    for(int i = 0; i < n ;i ++)
        if(a[i] < b[i]) swap(a[i], b[i]);
    int maxa, maxb; maxa = maxb = 0;
    for(int i = 0; i < n; i ++) {
        maxa = max(a[i], maxa);
        maxb = max(b[i], maxb);
    }
    cout << maxa * maxb << '\n';
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