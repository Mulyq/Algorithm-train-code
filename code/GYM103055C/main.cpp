#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

struct node {
    int x, y, z;
};
int cal(node a, node b) {
    int x = a.x - b.x;
    int y = a.y - b.y;
    int z = a.z - b.z;
    return x * x + y * y + z * z;
}
void solve() {
    vector<node> a(8);
    for(auto &[x, y ,z] : a) {
        cin >> x >> y >> z;
    }
    vector<int> e;
    for(int i = 0; i < 8; i ++) {
        for(int j = i + 1; j < 8; j ++) {
            e.push_back(cal(a[i], a[j]));
        }
    }
    sort(e.begin(), e.end());
    int cnt[3];
    int table = e[0];
    if(table == 0) {
        cout << "NO\n";
        return ;
    }
    memset(cnt , 0 , sizeof cnt);
    for(auto x : e) {
        if(x == table) {
            cnt[0] ++;
        } else if(x == table * 2) {
            cnt[1] ++;
        } else if(x == table * 3){
            cnt[2] ++;
        }
    }
    if(cnt[0] != 12 || cnt[1] != 12 || cnt[2] != 4) {
        cout << "NO\n";
        return ;   
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}