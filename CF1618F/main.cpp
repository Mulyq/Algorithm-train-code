#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
string get_binary(ll x) {
    string res;
    while(x) {
        res.push_back('0' + (x & 1));
        x >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}
bool KMP(string str, string prt) {
    int n = str.size(), m = prt.size();
    vector<int>next(m);
    for(int i = 1, k = 0; i < m; i ++) {
        while(k > 0 && prt[i] != prt[k])
            k = next[k - 1];
        if(prt[i] == prt[k])
            k ++;
        next[i] = k;
    }
    for(int i = 0, j = 0; i < n ; i ++) {
        while(j > 0 && str[i] != prt[j])
            j = next[j - 1];
        if(str[i] == prt[j])
            j ++;
        if(j == m)
            return 1;
    }
    return 0;
}
bool check(string a, string b) {
    bool f = 0;
    string tmp = a;
    tmp += '1';
    f = f | KMP(b, tmp);
    reverse(tmp.begin(), tmp.end());
    f = f | KMP(b, tmp);
    tmp = a;
    while(tmp.back() == '0') {
        tmp.pop_back();
    }
    f = f | KMP(b, tmp);
    reverse(tmp.begin(), tmp.end());
    f = f | KMP(b, tmp);
    return f;
}
void solve() {
    ll x, y;
    cin >> x >> y;
    auto a = get_binary(x);
    auto b = get_binary(y);
    if(x == y) {
        cout << "YES";
        return ;
    }
    if(!check(a, b)) {
        cout << "NO";
        return ;
    }
    if(b.back() == '0') {
        cout << "NO";
        return ;
    }
    while(b.back() == '1') b.pop_back();
    reverse(b.begin(), b.end());
    while(b.back() == '1') b.pop_back();
    string a1, a2;
    a1 = a2 = a;
    while(a1.back() == '1') a1.pop_back();
    reverse(a1.begin(), a1.end());
    while(!a1.empty() && a1.back() == '1') a1.pop_back();

    while(a2.back() == '0') a2.pop_back();
    
    while(a2.back() == '1') a2.pop_back();
    reverse(a2.begin(), a2.end());
    while(!a2.empty() && a2.back() == '1') a2.pop_back();

    bool f = 0;
    f = f | (a1 == b);
    reverse(a1.begin(), a1.end());
    f = f | (a1 == b);
    reverse(b.begin(), b.end());
    f = f | (a1 == b);
    reverse(a1.begin(), a1.end());
    f = f | (a1 == b);

    f = f | (a2 == b);
    reverse(a2.begin(), a2.end());
    f = f | (a2 == b);
    reverse(b.begin(), b.end());
    f = f | (a2 == b);
    reverse(a2.begin(), a2.end());
    f = f | (a2 == b);
    if(f) cout << "YES";
    else cout << "NO";
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