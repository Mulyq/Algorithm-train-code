#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> temp = a;
    int cnt = 0;
    while(temp.size()) {
        if(temp.size() && temp.back() == 0) {
            while(temp.size() && temp.back() == 0) temp.pop_back();
        } else if(temp.size() && temp.back() == 1) {
            while(temp.size() && temp.back() == 1) temp.pop_back();
            cnt ++;
        }
        if(cnt >= n || a[cnt] != cnt % 2) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}