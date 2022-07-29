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
    vector<int> ar(360);
    ar[0] = 1;
    int n;
    cin >> n;
    int now = 0;
    for(int i = 0; i < n; i ++) {
        int a;
        cin >> a;
        now = (now + a) % 360;
        ar[now] = 1;
    }
    int maxx = 0;
    int s = 0;
    for(int i = 1; i < 360; i ++) {
        if(ar[i] == 1) {
            maxx = max(maxx, i - s);
            s = i;
        }
    }
    maxx = max(maxx, 360 - s);
    cout << maxx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}