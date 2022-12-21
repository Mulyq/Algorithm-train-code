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
#define int long long
typedef pair<int, int> PII;
void solve() {
    int n;
    cin >> n;
    vector<int> even, odd;
    for(int i = 0;i < n;i ++) {
        int t;
        cin >> t;
        if(i % 2 == 0) {
            odd.push_back(t);
        }   else {
            even.push_back(t);
        }
    }
    int a = even[0], b = odd[0];
    for(auto i : even) {
        a = __gcd(a, i);
    }
    for(auto i : odd) {
        b = __gcd(b, i);
    }
    bool ok1 = 1;
    for(auto i : odd) {
        if(i % a == 0) ok1 = 0;
    }
    bool ok2 = 1;
    for(auto i : even) {
        if(i % b == 0) ok2 = 0;
    }
    if(ok1) {
        cout << a << '\n';
    }
    else if(ok2) {
        cout << b << '\n';
    }
    else {
        cout << 0 <<'\n';
    }

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
}