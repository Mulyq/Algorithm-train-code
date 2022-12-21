#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
bool cmp(vector<int> &a, vector<int> &b) {
    if(a.size() != b.size()) {
        return a.size() < b.size();
    }
    for(int i = 0; i < a.size(); i ++) {
        if(a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j ++) {
            a[i].push_back(s[j] - '0');
        }
    }
    int res = 0;
    for(int i = 1; i < n; i ++) {
        if(cmp(a[res], a[i])) {
            res = i;
        }
    }
    cout << res + 1 << '\n';
    for(auto x : a[res]) {
        cout << x;
    }
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