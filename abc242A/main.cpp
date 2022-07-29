#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    double res = 1;
    if(x <= a) {
    } else if(x <= b) {
        res = min(res, (double)(c) / double(b - a));
    } else {
        res = 0;
    }
    printf("%.12lf", res);

    return 0;
}