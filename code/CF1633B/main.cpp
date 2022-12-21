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
    cin >> s;
    int res = 0;
    int a = 0, b = 0;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '1') a++;
        else b ++;
        if(a != b) {
        res = max(res, min(a, b));
        }
    }
    a = b = 0;
    for(int i = s.size() - 1; i >= 0; i --){
        if(s[i] == '1') a++;
        else b ++;
        if(a != b) {
        res = max(res, min(a, b));
        }
    }
    cout << res << '\n';
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