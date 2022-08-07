#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
bool cmp(PII a, PII b) {
    if(a.first != b.second) return a.first < b.first;
    return a.second < b.second;
}
bool cmp2(PII a, PII b) {
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}
int main() {
    int n, t;
    scanf("%d %d",&n, &t);
    vector<PII> v(n);
    for(int i = 0; i < n; i ++) {
        scanf("%d%d", &v[i].first, &v[i].second);
    }
    sort(v.begin(), v.end());
    int res = 0;
    int r = 0;
    for(int i = 0; r < t;) {
        int l = r + 1;
        for(int j = i; j < n; j ++) {
            if(v[j].first <= l) {
                if(v[j].second >= l) {
                    r = max(r, v[j].second);
                }
            } else {
                i = j;
                break;
            }
        }
        if(l > r) {
            printf("%d",-1);
            return 0;
        } else {
            res ++;
        }
    }
    printf("%d", res);
    return 0;
}