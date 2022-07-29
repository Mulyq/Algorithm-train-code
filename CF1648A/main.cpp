#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
bool cmp(PII a, PII b) {
    return a.second < b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<PII>> mp(1e5 + 10);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            ll c;
            cin >> c;
            mp[c].push_back({i, j});
        }
    }
    ll res = 0;
    for(int i = 1; i < 1e5 + 9; i ++) {
        sort(mp[i].begin(), mp[i].end());
        vector<ll> b(mp[i].size());
        for(ll j = 0; j < mp[i].size(); j ++) {
            b[j] = mp[i][j].first;
        }
        for(ll j = 1; j < mp[i].size(); j ++) {
            b[j] += b[j - 1];
        }
        for(ll j = 1; j < mp[i].size(); j ++) {
            res += j * mp[i][j].first - b[j - 1];
        }
        sort(mp[i].begin(), mp[i].end(), cmp);
        for(ll j = 0; j < mp[i].size(); j ++) {
            b[j] = mp[i][j].second;
        }
        for(ll j = 1; j < mp[i].size(); j ++) {
            b[j] += b[j - 1];
        }
        for(ll j = 1; j < mp[i].size(); j ++) {
            res += j * mp[i][j].second - b[j - 1];
        }
    }
    cout << res;
    return 0;
}