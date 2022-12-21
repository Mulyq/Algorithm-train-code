#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {  
    string s;
    cin >> s;
    int a, b, c;
    a= b = c = 0;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == 'r') a ++;
        else if(s[i] == 'g') b ++;
        else if(s[i] == 'b') c ++;
        else if(s[i] == 'R') a --;
        else if(s[i] == 'G') b --;
        else c --;
        if(a < 0 || b < 0 || c < 0) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}