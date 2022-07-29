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
struct song {
    int p, s, q, idx;
};
bool cmp(song a, song b) {
    if(a.s != b.s) return a.s < b.s;
    return a.p < b.p;
}
void solve() {
    int n;
    cin >> n;
    vector<song> s(n);
    for(int i = 0;i < n;i ++) {
        cin >> s[i].p;
        s[i].idx = i + 1;
    }
    string str;
    cin >> str;
    for(int i = 0;i < n;i ++) {
        s[i].s = str[i] - '0';
    }
    sort(s.begin(), s.end(),cmp);
    for(int i = 0;i < n;i ++) {
        s[i].q = i + 1;
    }
    vector<int> res(n + 1);
    for(auto it : s) {
        res[it.idx] = it.q;
    }
    for(int i = 1;i <= n;i ++) {
        cout << res[i] << ' ' ;
    }
    cout << '\n';
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