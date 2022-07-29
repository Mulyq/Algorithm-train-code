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
// #include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    string s = "", t = "";
    for(int i = 0; i < n; i ++) {
        char tmp;
        cin >> tmp;
        s += tmp;
    }
    while(s.size()) {
        string sp = s;
        reverse(sp.begin(),sp.end());
        if(s < sp) {t += s[0]; s.erase(s.begin(), s.begin() + 1);}
        else {t += s[s.size() - 1]; s.erase(s.end() - 1, s.end());}
    }
    int cnt = 0;
    for(int i = 0; i < t.size(); i ++) {
        cout << t[i]; cnt ++;
        if(cnt % 80 == 0) cout << '\n';
        
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