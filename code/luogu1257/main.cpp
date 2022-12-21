#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

int main(){
    int  n;
    scanf("%d", & n);
    vector<PII> a(n);
    for(int i = 0; i < n; i ++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    double res = 1e18;
    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            double d = sqrt((a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second));
            res = min(res, d);
        }
    }
    printf("%.4lf", res);
    return 0;
}