#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int a[N], b[N], tmp[N], mp[N];
ll merge_sort(int q[], int l, int r) {
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    bool ok = 1, f = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
        if(mp[a[i]] > 1) {
            f = 1;
        }
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
        mp[b[i]] --;
        if(mp[b[i]] < 0) {
            ok = 0;
        }
    }
    if(ok) {
        if(f) {
            cout << "Yes\n";
            return 0 ;
        }
        if(merge_sort(a, 0, n - 1) % 2 == merge_sort(b, 0, n - 1) % 2){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}