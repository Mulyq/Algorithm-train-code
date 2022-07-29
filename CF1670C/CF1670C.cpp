#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
int tmp[MAXN];

ll merge_sort(vector<int> q, int l, int r) {
    if(l >= r) return 0;
    int mid = l + r >> 1;
    ll rec = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid  && j <= r) {
        if(q[i] <= q[j]) {
            tmp[k ++] = q[i ++];
        }
        else {
            tmp[k ++] = q[j ++];
            rec += mid - i + 1;
        }
    }
    while(i <= mid) tmp[k ++] = q[i ++];
    while(j <= r) tmp[k ++] = q[j ++];
    for(int i = l, k = 0; i <= r; i ++, k ++) q[i] = tmp[k];
    return rec;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    ll w1 = merge_sort(a, 0, n - 1);
    ll w2 = merge_sort(b, 0, n - 1);
    ll res = abs(w2 - w1);
    vector<int> d(n);
    for(int i = 0; i < n; i ++) {
        cin >> d[i];
    }
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