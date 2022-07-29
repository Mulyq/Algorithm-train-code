#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    vector<int> res;
    int i = 0;
    while (i < n) {
        int mex = 0;
        //find mex
        while(cnt[mex] > 0) {
            mex ++;
        }
        if(!mex) {
            res.push_back(0);
            i ++;
            continue;
        }
        vector<bool> alr(mex);
        int c = 0;
        int j = i;
        while(c < mex) {
            if(a[j] < mex && !alr[a[j]]) {
                alr[a[j]] = 1;
                c ++;
            }
            cnt[a[j]] --;
            j ++;
        }
        i = j;
        res.push_back(mex);
    }
    cout << res.size() << '\n';
    for(int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}