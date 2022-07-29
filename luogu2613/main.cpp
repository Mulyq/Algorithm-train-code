#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353, p = 19260817;
vector<int> div(vector<int> &A, ll b, ll &r) {
    vector<int> C;
    r = 0;
    for(int i = A.size() - 1; i >= 0; i --) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
    int d = a;
    if(b) {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1, y = 0;
    }
    return d;
}
void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> A, B;
    for(int i = s1.size() - 1; i >= 0; i --) {
        A.push_back(s1[i] - '0');
    }
    for(int i = s2.size() - 1; i >= 0; i --) {
        B.push_back(s2[i] - '0');
    }
    ll a, b;
    div(A, p, a);
    div(B, p, b);
    ll x, y;
    
    if(a % exgcd(b, p, x, y) != 0) {
        cout << "Angry!";
        return ;
    }
    
    cout << 1ll * a * ((x + p) % p) % p << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}