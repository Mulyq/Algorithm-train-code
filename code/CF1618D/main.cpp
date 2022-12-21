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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto & i : a) {
        cin >> i;
    }
    vector<int> b1, b2;
    sort(a.begin(), a.end()) ;
    for(int i = 0;i < k;i ++) {
        b1.push_back(a.back());
        a.pop_back();
    }
    for(int i = 0;i < k;i ++) {
        b2.push_back(a.back());
        a.pop_back();
    }
    int res = 0;
    for(auto i : a) {
        res += i;
    }
    for(int i = 0;i < k;i ++) { 
        res += b2[i] / b1[i];
    }
    cout << res << '\n';
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