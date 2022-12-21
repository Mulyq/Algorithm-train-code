#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k, vector<int> ());
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[x % k].push_back(x);
    }
    ll res = 0;
    for(int i = k - 1; i >= k / 2; i --) {
        int j = k - i;
        if(j > i) continue;
        while(a[i].size()) {
            int x = a[i].back();
            int y;
            a[i].pop_back();
            if(a[j].size()) {
                y = a[j].back();
                a[j].pop_back();
            } else {
                j ++;
                a[i].push_back(x);
                if(i < j) {
                    break;
                }
                continue;
            }
            res += (x + y) / k;
        }
    }
    queue<int> q;
    for(int i = 0; i < k; i ++) {
        while(a[i].size()) {
            q.push(a[i].back());
            a[i].pop_back();
        }
    }
    while(q.size()) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        res += (x + y) / k;
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}