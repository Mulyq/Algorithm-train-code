#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    string s;
    int k;
    cin >> s >> k;
    if(k >= s.size()) {
        cout << 0;
        return ;
    }
    int j = 1;
    for(int i = 0; i < k; i ++) {
        while(s[j] >= s[j - 1] && j < s.size()) {
            j ++;
        }
        s.erase(s.begin() + j - 1, s.begin() + j);
        while(s.front() == '0') {
            s.erase(s.begin(), s.begin() + 1);
        }
        j --;
    }
    if(s.empty()) {
        cout << 0;
    } else
        cout << s ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}