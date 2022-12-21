#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
void solve() {
    int n, m;
    cin >> m >> n;
    vector <vector<int> >p(n, vector<int>(m));
    for(int i = 0;i < m;i ++) {
        for(int j = 0;j < n;j ++) {
            cin >> p[j][i];
        }
    }
    int l = 0, r = 1e9 + 1;
    for(int i = 0;i < n;i ++) {
        r = min(r,*max_element(p[i].begin(),p[i].end()));
    }
    while(l < r) {
        bool f = 0;
        int mid = l + r + 1 >> 1;
        vector<bool> v(m,0);
        for(int i = 0;i < n;i ++) {
            for(int j = 0;j < m;j ++) {
                if(p[i][j] >= mid){
                    if(v[j]) {
                        f = 1;
                    }
                    v[j] = 1;
                }
            }
        }
        if(f) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
}
int main(){
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}