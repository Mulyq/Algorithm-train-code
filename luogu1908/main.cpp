#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
ll ask(vector<int> &a, int l, int r) {
    ll res = 0;
    if(l >= r) return 0;
    vector<int> temp;
    int mid = l + r >> 1;
    res = ask(a, l, mid) + ask(a, mid + 1, r);
    int i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i ++]);
        } else {
            temp.push_back(a[j ++]);
            res += mid - i + 1;
        }
    }
    while (i <= mid) {
        temp.push_back(a[i ++]);
    }
    while (j <= r) {
        temp.push_back(a[j ++]);
    }
    for(int i = l, j = 0; i <= r; i ++) {
        a[i] = temp[j ++];
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    cout << ask(a, 0, n - 1);
    return 0;
}