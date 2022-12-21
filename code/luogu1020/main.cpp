#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
/*
1、最长不下降子序列长度
2、最长上升子序列长度
*/
void solve() {
    vector<int> a;
    vector<int> vmx, vmi;
    int x;
    while (cin >> x) {
        a.push_back(x);
    }
    int n = a.size();
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        if(!i) vmx.push_back(a[i]);
        else {
            if(vmx.back() >= a[i]) {
                vmx.push_back(a[i]);
            } else {
                *lower_bound(vmx.begin(), vmx.end(),  a[i], [&] (const int &a, const int & b) {
                    return a >= b;
                }) = a[i];
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        if(!i) {
            vmi.push_back(a[i]);
        } else {
            if(vmi.back() < a[i]) {
                vmi.push_back(a[i]);
            } else {
                *lower_bound(vmi.begin(), vmi.end(), a[i], [&] (const int & a, const int & b) {
                    return a < b;
                }) = a[i];
            }
        }
    }
    // for(auto x : vmi) {
    //     cout << x << ' ';
    // }
    // cout << '\n';
    // for(auto x : vmx) {
    //     cout << x << ' ';
    // }
    cout << vmx.size() << '\n' << vmi.size() << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}