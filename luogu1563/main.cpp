#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector< pair<string, int> > a(n);
    for(int i = 0 ; i < n; i ++) {
        cin >> a[i].second >> a[i].first;
    }
    int res = 0;
    while(q --) {
        int rl, num;
        cin >> rl >> num;
        bool dir = (rl + a[res].second) % 2;
        if(dir) {
            res += num;
        } else {
            res -= num;
        }
        res = (res + n) % n;
    }
    cout << a[res].first;
    return 0;
}