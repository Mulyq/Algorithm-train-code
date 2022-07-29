#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
string s;
ll n;
vector<ll> len;
void f(ll x) {
    if(x < s.size()) {
        cout << s[x] << '\n';
        return ;
    }
    while(len.back() > x) {
        len.pop_back();
    }
    f((x - 1) % len.back());
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> n;
    len.push_back(s.size());
    n --;
    ll l = s.size();
    for(ll i = 2; l < n / i; i *= 2) {
        len.push_back(i * l);
    }
    f(n);
    return 0;
}