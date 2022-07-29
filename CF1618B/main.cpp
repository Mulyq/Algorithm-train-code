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
    int n;
    cin >> n;
    vector<string> s(n - 2);
    for(auto &i : s) {
        cin >> i;
    }
    string res = s[0];
    for(int i = 1;i < n - 2;i ++) {
        if(res.back() != s[i][0]) {
            res += s[i];
        }
        else {
            res.pop_back();
            res += s[i];
        }
    }
    while(res.size() < n) {
        res += 'a';
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >>T ;
    while(T --) {
        solve();
    }
    return 0;
}