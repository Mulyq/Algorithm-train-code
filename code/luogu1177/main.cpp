#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
void quicksort(vector<int> &a, int l, int r) {
    if(l >= r) {
        return ;
    }
    int x = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while(i < j) {
        do i ++; while(x > a[i]);
        do j --; while(x < a[j]);
        if(i < j) {
            swap(a[i], a[j]);
        }
    }
    quicksort(a, l, j), quicksort(a, j + 1, r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for(auto x : a) {
        cout << x << ' ';
    }
    return 0;
}