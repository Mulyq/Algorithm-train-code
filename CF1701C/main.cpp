#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        a[x] ++;
    }
    vector<int> ban(n + 1);
    int ex = 0;
    sort(a.rbegin(), a.rend() - 1);
    for(int t = 1; t < INF; t ++) {
        ex = 0;
        for(int i = 1; i <= n; i ++) {
            if(a[i] && !ban[i]) {
                a[i] --;
                m --;
                if(!m) break;
            } else if(!a[i] && !ban[i]){
                ban[i] = 1;
                m --;
                ex = 1;
            } else {
                ban[i] = 0;
            }
        }
        if(m <= 0) {
            cout << t + ex << '\n';
            return ;
        }
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
    return 0;
}