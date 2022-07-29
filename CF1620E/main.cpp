#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 5e5 + 10;
int q, x, y, op;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    vector<int>idx[N], a;
    while(q --) {
        cin >> op;
        if(op == 1) {
            cin >> x;
            a.push_back(x);
            idx[x].push_back(a.size() - 1);
        }
        else {
            cin >> x >> y;
            if(x != y){
                if(idx[x].size() > idx[y].size())
                    idx[x].swap(idx[y]);
                for(auto it : idx[x]) {
                    idx[y].push_back(it);
                }
                idx[x].clear();
            }
        }
    }
    for(int i = 0;i < N;i ++) {
        for(auto it : idx[i]) {
            a[it] = i;
        }
    }
    for(auto it : a) {
        cout << it << ' ';
    }
    return 0;
}