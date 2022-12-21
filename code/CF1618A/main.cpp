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

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
void solve() {
    vector<int> a(7);
    for(auto & i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end()) ;
    cout << a[0] << ' '<< a[1] << ' ' << a[6] - a[0] - a[1] <<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}