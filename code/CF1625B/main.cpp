#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
void solve() {
    int n;
    int res = -1;
    cin >> n;
    vector<int>a(n);
    vector<int>num(150001, -1);
    for(auto &it : a) {
        cin >> it;
    }
    for(int i = 0;i < n;i ++) {
        if(num[a[i]] == -1) {
            num[a[i]] = i;
        }
        else {
            res = max(res,n - (i - num[a[i]])); 
            num[a[i]] = i;
        }
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}