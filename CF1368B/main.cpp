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

void solve() {
    ll n;
    cin >> n;
    int k = 0;
    for(int i = 1; i <= 40;i ++) {
        if((ll)pow(i, 10) >= n) {
            k = i;
            break;
        }
    }
    int x = 0;
    for(int i = 1; i <= 10; i ++) {
        if((ll)pow(k,i) * (ll)pow(k - 1,10 - i) >= n && n >= (ll)pow(k,i - 1) * (ll)pow(k - 1, 11 - i)) {
            x = i;
            break;
        }
    }
    string s = "codeforces";
    for(int i = 0; i < x; i ++) {
        for(int j = 0; j < k; j ++) {
            cout << s[i];
        }
    }
    for(int i = x; i < 10; i ++) {
        for(int j = 0; j < k - 1; j ++) {
            cout << s[i];
        }
    }
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