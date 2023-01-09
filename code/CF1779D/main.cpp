#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    bool ok = 1;
    stack<PII> stk;
    for(int i = 0; i < n; i ++) {
        if(stk.empty()) {
            stk.push({i, 0});
        } else {
            if(b[i] < b[stk.top().first]) {
                stk.push({i, 0});
            } else if(b[i] > b[stk.top().first]) {
                while(stk.size() && b[i] > b[stk.top().first]) {
                    if(stk.top().second) {
                        cnt[b[stk.top().first]] ++;
                    }
                    stk.pop();
                }
                if(stk.empty() || b[stk.top().first] != b[i]) {
                    stk.push({i, 0});
                }
            }
        }
        if(b[i] > a[i]) {
            ok = 0;
        } else if(b[i] < a[i]) {
            stk.top().second |= 1;
        }
    }
    while(stk.size()) {
        if(stk.top().second) {
            cnt[b[stk.top().first]] ++;
        }
        stk.pop();
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i ++) {
        int x;
        cin >> x;
        if(cnt.find(x) != cnt.end()) {
            cnt[x] --;
        }
    }
    for(auto &[x, c] : cnt) {
        if(c > 0) {
            ok = 0;
        }
    }
    if(ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}