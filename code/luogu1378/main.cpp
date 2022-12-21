#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535;
double cal(double r) {
    return PI * r * r;
}
void solve() {
    int n, x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    double all = abs(y2 - y1) * abs(x2 - x1);
    vector<PII> node(n);
    for(int i = 0; i < n; i ++) {
        cin >> node[i].first >> node[i].second;
    }
    vector<int> xl(n);
    for(int i = 0; i < n; i ++) xl[i] = i;
    double res = all;
    do {
        vector<pair<PII, double>> al; 
        double S = 0;
        for(int i = 0; i < n; i ++) {
            double r = min(abs(node[xl[i]].first - x1), abs(node[xl[i]].first - x2));
            r = min(r, (double)abs(node[xl[i]].second - y1));
            r = min(r, (double)abs(node[xl[i]].second - y2));
            for(auto it : al) {
                int x = it.first.first, y = it.first.second;
                double d = sqrt(pow(node[xl[i]].first - x, 2) + pow(node[xl[i]].second - y, 2));
                r = min(r, max(0.0, d - it.second));
            }
            S += cal(r);
            al.push_back({{node[xl[i]].first, node[xl[i]].second}, r});
        }
        res = min(res, all - S);
    } while(next_permutation(begin(xl), end(xl)));
    printf("%.0lf", res);
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