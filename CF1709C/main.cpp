#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
bool check(string s) {
    int x = 0;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == '(') x ++;
        else x --;
        if(x < 0) return 0;
    }
    return 1;
}
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if(s[0] == ')' || s[n - 1] == '(') {
        cout << "NO\n";
        return ;
    }
    s[0] = '(', s[n - 1] = ')';
    int a, b, c;
    a = b = c = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] =='(') a ++;
        else if(s[i] == ')') b ++;
        else c ++;
    }
    if(a == b && a == 0) {
        cout << "YES\n";
        return;
    }
    int x = 0;
    string t = s;
    vector<int> p, q;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '(') x ++, a --;
        else if(s[i] ==')') x --, b --;
        else {
            if(x == 0) {
                c --;
                x ++;
                t[i] = '(';
            } else {
                if(b + c - a - x == 0) {
                    x --, c --;
                    t[i] = ')';
                    q.push_back(i);
                } else {
                    x ++, c --;
                    t[i] = '(';
                    // if(x > 2)
                        p.push_back(i);
                }
            }
        }
        if(x < 0) {
            cout << "NO\n";
            return ;
        }
    }
    if(q.size() && p.size()) {
        int l = p[0], r = q[q.size() - 1];
        for(int i = 0; i < q.size(); i ++) {
            r = q[i];
            swap(t[l], t[r]);
            if(check(t)) {
                cout << "NO\n";
                return ;
                swap(t[l], t[r]);
            }
        }
    }
    cout << "YES\n";
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