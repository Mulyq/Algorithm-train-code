#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    stack<PII> cnr;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[x] ++;
    }
    ll keng = 0;
    for(int i = 0; i <= n; i ++) {
        if(a[i]) {
            cout << a[i] + keng << ' ';
            if(a[i] > 1)
                cnr.push({i, a[i] - 1});
        } else {
            if(cnr.size()) {
                cout << keng << ' ';
                keng += i - cnr.top().first;
                cnr.top().second --;
                if(!cnr.top().second) cnr.pop();
            } else {
                for(int j = i; j <= n; j ++) {
                    if(j == i) cout << keng << ' ';
                    else cout << -1 << ' ';
                }
                cout << '\n';
                return;
            }
        }
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