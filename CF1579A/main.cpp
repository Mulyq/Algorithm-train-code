#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;

void solve() {
string s;
    cin >> s;
    int a, b ,c;
    a = b = c = 0;
    for(int i = 0;i < s.size() ;i ++) {
        if(s[i] == 'A')a ++;
        else if (s[i] == 'B')b ++;
        else c ++;
    }
    if(a + c == b)cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}