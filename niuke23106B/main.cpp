#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
struct ST {
    vector<vector<vector<int>>> st;
    ST(vector<int> a) {
        int n = a.size();
        st.resize(3, vector<vector<int>> (n, vector<int> (log2(n) + 1)));
        for(int i = 0; i < n; i ++) {
            st[1][i][0] = st[2][i][0] = a[i];
            st[0][i][0] = max(a[i], 0);
        }
        for(int j = 1; j <= log2(n); j ++) {
                for(int k = 0; k + (1 << j) - 1 < n; k ++) {
            for(int i = 0; i < 3; i ++) {
                    st[i][k][j] = st[i][k][j - 1] + st[(i + st[i][k][j - 1] + 3) % 3][k + (1 << (j - 1))][j- 1];
                }
            }
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'W') a[i] = 1;
        else if(s[i] == 'L') a[i] = - 1;
        else a[i] = 0;
    }
    ST sheet(a);
    while(m --) {
        int l, r, s;
        cin >> l >> r >> s;
        l--, r--;
        int k = s % 3, res = s;
        int now = l;
        while(now <= r) {
            int i = log2(r - now + 1);
            res += sheet.st[k][now][i];
            now += (1 << i);
            k = res % 3;
        }
        cout << res << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}