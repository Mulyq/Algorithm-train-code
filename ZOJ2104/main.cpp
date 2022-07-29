#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int n = 0;
void solve() {
    map <string,int> mp;
    for(int i = 0 ; i < n; i ++) {
        string s;
        cin >> s;
        mp[s] ++;
    }
    string res = "";
    int maxx = 0;
    for(auto x : mp) {
        if(x.second > maxx) {
            maxx = x.second;
            res = x.first;
        }
    }
    cout << res <<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        solve();
    }
    return 0;
}