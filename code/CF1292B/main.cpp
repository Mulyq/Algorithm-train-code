#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
ll x0, y0, ax, ay, bx, by;
ll x, y;
void cal() {
    x = ax * x + bx;
    y = ay * y + by;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;
    x = x0, y = y0;
    vector<pair<ll, ll>> v;
    do {
        ll T = abs(xs - x) + abs(ys - y);
        if(T > t) {
            if(x > xs && y > ys) break;
        } else {
            v.push_back({x, y});
        }
        cal();
    } while(1);
    int res = 0;
    for(int i = 0; i < v.size(); i ++) {
        int c = 1;
        ll T = abs(xs - v[i].first) + abs(ys - v[i].second);
        x = v[i].first, y = v[i].second;
        for(int j = i - 1; j >= 0; j --) {
            if(T + x - v[j].first + y - v[j].second <= t) {
                T += x - v[j].first + y - v[j].second;
                x = v[j].first, y = v[j].second;
                c ++;
            }
        }
        for(int j = i + 1; j < v.size(); j ++) {
            if(T + v[j].first + v[j].second - x - y <= t) {
                T += v[j].first + v[j].second - x - y;
                x = v[j].first, y = v[j].second;
                c ++;
            }
        }
        res = max(res, c);
    }
    cout << res << '\n';
}