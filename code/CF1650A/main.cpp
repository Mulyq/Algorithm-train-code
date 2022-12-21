#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    string s;
    char c;
    cin >> s >> c;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == c) {
            if(i % 2 == 0 ) {
                cout << "Yes\n";
                return ;
            }
        }
    }
    cout << "No\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}