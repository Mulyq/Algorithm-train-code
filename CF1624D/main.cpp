#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
void solve() {
    int n, k, sum = 0, rest = 0;

    string s;
    cin >> n >> k >> s;
    vector<int>a(26);
    for(int i = 0;i < n;i ++) {
        a[s[i] - 'a'] ++;
    }
    for(int i = 0;i < 26;i ++) {
        sum += int(a[i] >> 1) * 2;
        a[i] -= (int(a[i] >> 1)) * 2;
    }
    for(int i = 0;i < 26;i ++) {
        rest += a[i];
    }
    int res = sum / k;
    rest += sum - res * k;
    if(rest >= k && res % 2 == 0) {
        res ++;
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}