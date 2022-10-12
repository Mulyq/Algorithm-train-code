#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, r[3], c[3], tx, ty;
    cin >> n;
    for(int i = 0; i < 3; i ++) {
        cin >> r[i] >> c[i];
    }
    cin >> tx >> ty;
    bool ok = 0;
    for(int i = 0; i < 3; i ++) {
        int x = r[i], y = c[i];
        if(x + y > 3 && y - x < n - 2 && x - y < n - 2 && y + x < 2 * n - 1) {
            ok = 1;
        }
    }
    if(!ok) {
        for(int i = 0; i < 3; i ++) {
            if(r[i] == 1 && c[i] == 1) {
                if(tx == 1 || ty == 1) {
                    cout << "YES\n";
                    return;
                }
            } else if(r[i] == 1 && c[i] == n) {
                if(tx == 1 || ty == n) {
                    cout << "YES\n";
                    return;
                }
            } else if(r[i] == n && c[i] == 1) {
                if(tx == n || ty == 1) {
                    cout << "YES\n";
                    return;
                }
            } else if(r[i] == n && c[i] == n) {
                if(tx == n || ty == n) {
                    cout << "YES\n";
                    return;
                }
            }
        }
        cout << "NO\n";
        return;
    }
    int b = 0, w = 0, tag[2];
    for(int i = 0; i < 3; i ++) {
        if((r[i] + c[i]) % 2 == 0) {
            w ++;
            tag[0] = i;
        } else {
            b ++;
            tag[1] = i;
        }
    }
    if(b > w) {
        b = 1;
        w = 0;
    } else {
        w = 1;
        b = 0;
    }
    if((tx + ty) % 2 == 0) {
        if(w) {
            cout << "YES\n";
        } else {
            if((tx - r[tag[0]]) % 2 == 0 && (ty - c[tag[0]]) % 2 == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    } else {
        if(b) {
            cout << "YES\n";
        } else {
            if((tx - r[tag[1]]) % 2 == 0 && (ty - c[tag[1]]) % 2 == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
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