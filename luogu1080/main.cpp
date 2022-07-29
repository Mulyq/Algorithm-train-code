#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
vector<int> cmp(vector<int> a, vector<int> b) {
    bool ok = 0;
    if(a.size() != b.size()) {
        ok = a.size() < b.size();
    } else {
        for(int i = a.size() - 1; i >= 0; i --) {
            if(a[i] != b[i]) {
                ok = a[i] < b[i];
                break;
            }
        }
    }
    if(ok) return b;
    else return a;
}
vector<int> mul(vector<int> a, int b) {
    vector<int> res;
    int t = 0;
    for(int i = 0; i < a.size() || t ; i ++) {
        if(i < a.size()) {
            t += a[i] * b;
        }
        res.push_back(t % 10);
        t /= 10;
    }
    while(res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }
    return res;
}
vector<int> div(vector<int> a, int b) {
    vector<int> res;
    int r = 0;
    for(int i = a.size() - 1; i >= 0; i --) {
        r = r * 10 + a[i];
        res.push_back(r / b);
        r %= b;
    }
    reverse(res.begin(), res.end());
    while(res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<PII> a(n + 1);
    for(int i = 0; i <= n; i ++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(), [&](PII x, PII y) {
        return x.first * x.second < y.first * y.second;
    });
    vector<int> res(1);
    vector<int> k(1, 1);
    k = mul(k, a[0].first);
    for(int i = 1; i <= n; i ++) {
        res = cmp(res, div(k, a[i].second));
        k = mul(k, a[i].first);
    }
    for(int i = res.size() - 1;  i >= 0; i --) {
        cout << res[i];
    }
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