#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    set<int> s;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int i = 1, j = 2;
    for(; j <= n ; j ++) {
        if (a[j] < a[i]) {
            s.insert(i);
            i = j;
        }
    }
    s.insert(i);
    for(int i = 0; i < m; i ++) {
        int k, d;
        cin >> k >> d;
        int l;
        auto temp = s.upper_bound(k);
        l = *(-- temp);
        a[k] -= d;
        temp ++;
        while(temp != s.end()) {
            if(a[*temp] >= a[k]) {
                s.erase(temp ++);
            } else {
                break;
            }
        }
        if(a[k] < a[l]) {
            s.insert(k);
        }
        cout << s.size() << ' ';
    }
    cout << '\n';
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