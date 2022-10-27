#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
const double PI = 3.1415926535;
int main() {
    int T;
    cin >> T;
    array<pair<double, double>, 3> p;
    array<int, 3> t, l;
    for(int i = 0; i < 3; i ++) {
        cin >> l[i];
        p[i].first = l[i];
        p[i].second = 0;
    }
    for(int i = 0; i < 3; i ++) {
        cin >> t[i];
    }
    for(int i = 0; i < 3; i ++) {
        double r = -2 * PI * (T % t[i]) / t[i] + PI / 2;
        p[i].first = l[i] * cos(r);
        p[i].second = l[i] * sin(r);
    }
    pair<double, double> res = {0, 0};
    for(int i = 0; i < 3; i ++) {
        res.first += p[i].first;
        res.second += p[i].second;
    }
    printf("%.9f %.9f", res.first, res.second);
}