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
    int n, sum;
    cin >> n >> sum;
    vector<PII> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i ++) {
        cin >> a[i].second;
    }
    sort(a.begin(),a.end());
    for(int i = 0; i < n; i ++) {
        if(sum >= a[i].first) sum += a[i].second;
    }
    cout << sum << '\n';
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