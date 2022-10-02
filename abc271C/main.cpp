#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    unique(a.begin(), a.end());
    int res = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] != res + 1 && n - i >= 2) n -= 2, res ++, i --;
        else if(a[i] == res + 1) res ++;
    }
    cout << res << '\n';
}