#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int res = -1;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == 'a') {
            res = i + 1;
        }
    }
    cout << res << '\n';
}