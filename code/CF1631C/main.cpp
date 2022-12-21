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
    vector<int> a(n), p(n);
    for(int i = 0; i < n / 2; i ++) {
        a[i] = i, a[n / 2 + i] = n - 1 - i;
        p[i] = i, p[n - 1 - i] = n / 2 + i;
    }
    if(n - 1 == k) {
        if(n == 4) {
            cout << -1 << '\n';
            return;
        }
        else {
            swap(a[0], a[n / 2 + 1]), swap(a[n / 2 + 1], a[n / 2 - 1]);
        }
    }
    else {
        swap(a[p[k]], a[p[0]]);
    }
    for(int i = 0; i < n / 2; i ++) {
        cout << a[i] << ' ' << a[n / 2 + i] << '\n';
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