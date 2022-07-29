#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> res(n);
    vector<int> pla(n + 1);
    for(int i = 0 ; i < n; i ++) {
        cin >> a[i];
        pla[a[i]] = i;
    }
    if(n == 1) {
        cout << -1 << '\n';
        return ;
    }
    int blank = -1;
    for(int i = 0; i < n; i ++) {
        if(a[i] != i + 1 && res[i] == 0) res[i] = i + 1;
        else {
            if(blank == -1) {
                int l = i + 1;
                while(l < n && res[l] != 0) {
                    l ++;
                }
                if(l == n) {
                    l --;
                    res[l] = i + 1;
                    swap(res[l], res[l - 1]);
                } else {
                    res[l] = i + 1;
                }
                blank = i;
            } else {
                res[blank] = i + 1;
                blank = -1;
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        cout << res[i] << ' ';
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