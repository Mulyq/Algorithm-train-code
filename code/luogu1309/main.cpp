#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
struct per {
    int idx, soc, w;
    const bool operator< (const per &a) const {
        if(soc != a.soc) return soc > a.soc;
        return idx < a.idx;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r, q;
    cin >> n >> r >> q;
    vector<per> a(2 * n);
    for(int i = 1; i <= 2 * n; i ++) {
        cin >> a[i - 1].soc;
        a[i - 1].idx = i;
    }
    for(int i = 1; i <= 2 * n; i ++) {
        cin >> a[i - 1].w;
    }
    sort(a.begin(), a.end());
    while (r --) {
        vector<per> winner, loser;
        for(int i = 0; i < n; i ++) {
            if(a[2 * i].w > a[2 * i + 1].w) {
                a[2 * i].soc ++;
                winner.push_back(a[2 * i]), loser.push_back(a[2 * i + 1]);
            } else {
                a[2 * i + 1].soc ++;
                winner.push_back(a[2 * i + 1]), loser.push_back(a[2 * i]);
            }
        }
        merge(winner.begin(), winner.end(), loser.begin(), loser.end(), a.begin());
    }
    cout << a[q - 1].idx;
    return 0;
} 