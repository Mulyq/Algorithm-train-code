#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> cnt(c + 1), sum(c + 1);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    for(int i = 1; i <= c; i ++) {
        sum[i] = sum[i - 1] + cnt[i];
    }
    for(int y = 1; y <= c; y ++) {
        if(!cnt[y]) {
            continue;
        }
        for(int i = 1; i * y <= c; i ++) {
            int r = min(c, i * y - 1 + y);
            if(sum[r] - sum[i * y - 1] > 0) {
                if(cnt[i] == 0) {
                    cout << "No\n";
                    return ;
                }
            }
        }
    }
    cout << "Yes\n";
    return ;
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