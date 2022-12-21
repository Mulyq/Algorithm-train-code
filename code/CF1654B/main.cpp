#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    vector<int> a(26);
    for(int i = 0; i < s.size(); i ++) {
        a[s[i] - 'a'] ++;
    }
    int i = 0;
    while(a[s[i] - 'a'] != 1) {
        a[s[i] - 'a'] --;
        i ++;
    }
    for(; i < s.size(); i ++) {
        cout << s[i];
    }
    cout << '\n';
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