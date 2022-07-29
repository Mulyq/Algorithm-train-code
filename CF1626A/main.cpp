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
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
void solve() {
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while( T --) {
        solve();
    }
    return 0;
}