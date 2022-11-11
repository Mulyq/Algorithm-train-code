#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int mi = 0;
    vector<int> post, ins;
    vector<PII> res;
    ll all = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(x > 0) post.push_back(x);
        else ins.push_back(x);
    }
    sort(post.begin(), post.end());
    sort(ins.begin(), ins.end());
    if(!ins.size()) {
        for(int i = 1; i < n - 1; i ++) {
            res.push_back({post[0], post[i]});
            post[0] -= post[i];
        }
        res.push_back({post[n - 1], post[0]});
        all = post[n - 1] - post[0];
    } else if( !post.size()) {
        for(int i = n - 2; i >= 0; i -- ) {
            res.push_back({ins[n - 1], ins[i]});
            ins[n - 1] -= ins[i];
        }
        all = ins[n - 1];
    } else {
        for(int i = 1; i < post.size(); i ++) {
            res.push_back({ins[0], post[i]});
            ins[0] -= post[i];
        }
        for(int i = 0; i < ins.size(); i ++) {
            res.push_back({post[0], ins[i]});
            post[0] -= ins[i];
        }
        all = post[0];
    }
    cout << all << '\n';
    for(auto &[x, y] : res) {
        cout << x << ' ' << y << '\n';
    }
}