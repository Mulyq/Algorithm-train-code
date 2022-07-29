#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
string s;
int n;
ll t, k;
int dfs(ll t, ll k) {
    if(t == 0) {
        return s[k] - 'A';
    } else {
        if(k == 0) {
            return (s[k] - 'A' + t ) % 3ll;
        } else {
            return (dfs(t - 1, k >> 1) + k % 2 + 1) % 3;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> n;
    for(int i = 0; i < n; i ++) {
        cin >> t >> k; k --;
        char res = dfs(t, k) + 'A';
        cout << res << '\n';
    }
    return 0;
}