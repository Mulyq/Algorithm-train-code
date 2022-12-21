#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    int res = 0;
    vector<int>two(31, 0);
    for(int i = 0; i < k; i ++) {
        for(auto &it : a) {
            if((it & 1) == 1) {
                two[i] ++;
            }
            it >>= 1;
        }
    }
    for(int i = 0;i < k;i ++) {
        if(two[i] * 2 > n) {
            res += (1 << i);
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