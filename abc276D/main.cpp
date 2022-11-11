#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> s2(n), s3(n);
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        while(a[i] % 2 == 0) {
            a[i] /= 2;
            s2[i] ++;
        }
        while(a[i] % 3 == 0) {
            a[i] /= 3;
            s3[i] ++;
        }
    }
    for(int i = 0; i < n; i ++) {
        if(a[i] != a[0]) {
            cout << "-1\n";
            return 0;
        }
    }
    ll all = 0;
    int m2 = INF, m3 = INF;
    for(int i = 0; i < n; i ++) {
        all += s2[i] + s3[i];
        m2 = min(m2, s2[i]);
        m3 = min(m3, s3[i]);
    }
    all -= n * m2 + n * m3;
    cout << all << '\n';
}