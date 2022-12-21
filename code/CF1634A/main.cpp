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
    string s;
    int n, k;
    cin >> n >> k >> s;
    if(k == 0) {
        cout << 1 << '\n';
        return;
    }
    for(int i = 0, j = s.size() - 1; i < j ; i ++, j--) {
        if(s[i] != s[j]) {
            cout << 2 << '\n';
            return ;
        }
    }
    cout << 1 <<'\n';
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