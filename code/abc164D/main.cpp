#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> cnt(2019);
    cnt[0] = 1;
    int now = 0;
    ll res = 0;
    int p = 1;
    for(int i = s.size() - 1; i >= 0; i --) {
        now = (now + (s[i] - '0') * p) % 2019;
        res += cnt[now] ++;
        (p *= 10) %= 2019;
    }
    cout << res << '\n';
}