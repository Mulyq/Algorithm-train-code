#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
void solve() {
    int n;
    cin >> n;
    set<int> S;
    vector<int> cnt(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x;
        cin >> x;
        S.insert(x);
        cnt[x] ++;
    }
    sort(cnt.begin(), cnt.end(), [&] (const int &a, const int &b) {
        return a > b;
    });
    int k = S.size() + 1;
    int temp = k;
    priority_queue<int> q;
    for(int i = 0; i < n - 1; i ++) {
        int x = cnt[i] - temp;
        temp --;
        temp = max(temp, 0);
        if(x > 0) q.push(x);
    }
    int tt = 0;
    while(q.size() && q.top() > tt) {
        int x = q.top();
        q.pop();
        x --; q.push(x);
        tt ++;
    }
    cout << k + tt << '\n';
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