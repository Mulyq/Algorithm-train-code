#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
int quer(string s) {
    cout << "? " << s << '\n';
    int x;
    cin >> x;
    return x;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<PII> e;
    for(int i = 0; i < m; i ++) {
        string s;
        for(int j = 0; j < m; j ++) {
            if(i == j) {
                s += '1';
            } else {
                s += '0';
            }
        }
        int val = quer(s);
        e.push_back({val, i});
    }
    sort(e.begin(), e.end());
    int res = 0;
    string s;
    for(int i = 0; i < m; i ++) {
        s += '0';
    }
    for(int i = 0; i < m; i ++) {
        s[e[i].second] = '1';
        int temp = quer(s);
        if(temp != res && temp - res == e[i].first) {
            res = temp;
        } else {
            s[e[i].second] = '0';
        }
    }
    cout << "! " << res << '\n';
    return 0;
}