#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
ll merge_sort(vector<int> &q, int l, int r) {
    if(l >= r) return 0;
    int mid = l + r >> 1;
    ll rec = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    vector<int> temp;
    while(i <= mid  && j <= r) {
        if(q[i] <= q[j]) {
            temp.push_back(q[i ++]);
        }
        else {
            temp.push_back(q[j ++]);
            rec += mid - i + 1;
        }
    }
    while(i <= mid) temp.push_back(q[i ++]);
    while(j <= r) temp.push_back(q[j ++]);
    for(int i = l, k = 0; i <= r; i ++, k ++) q[i] = temp[k];
    return rec;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll res = 0;
    vector<int> all(26), cnt(26);
    for(int i = 0; i < n; i ++) {
        all[s[i] - 'a'] ++;
    }
    string l, r;
    for(int i = 0; i < n; i ++) {
        if(cnt[s[i] - 'a'] < (all[s[i] - 'a'] / 2)) {
            cnt[s[i] - 'a'] ++;
            res += i - l.size();
            l.push_back(s[i]);
        } else {
            r.push_back(s[i]);
        }
    }
    // cout << l << ' '<< r << '\n';
    vector<deque<int>> pos(26);
    for(int i = 0; i < n / 2; i ++) {
        pos[l[i] - 'a'].push_back(i);
    }
    vector<int> a(n / 2);
    for(int i = 0; i < n / 2; i ++) {
        a[i] = pos[r[i] - 'a'].front();
        pos[r[i] - 'a'].pop_front();
    }
    // for(int i = 0; i < n / 2; i ++) {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    res += merge_sort(a, 0, n / 2 - 1);
    cout << res << '\n';
}