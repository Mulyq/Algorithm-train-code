#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<PII> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].second >> a[i].first ;
   }
    sort(a.begin(), a.end(), [&] (PII x, PII y) {
        if(x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });
    int rnk = m * 1.5;
    int bank = a[rnk - 1].first;
    vector<PII> res;
    for(int i = 0; i < n; i ++) {
        if(a[i].first >= bank) {
            res.push_back(a[i]);
        }
    }
    cout << bank << ' ' << res.size() << '\n';
    for(PII x : res) {
        cout << x.second << ' ' << x.first << '\n';
    }
    return 0;
}