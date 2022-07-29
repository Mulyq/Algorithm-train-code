#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), fa(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        fa[a[i]] = i;
    }
    vector<bool> vis(n + 1);
    vector<vector<int>> A;
    vector<int> posA;
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) {
            vector<int> huan;
            int ff = i;
            do {
                vis[ff] = 1;
                huan.push_back(ff);
                ff = fa[ff];
            } while(ff != i);
            A.push_back(huan);
            posA.push_back(i);
        }
    }

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        fa[a[i]] = i;
        vis[i] = 0;
    }
    vector<vector<int>> B;
    vector<int> posB;
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) {
            vector<int> huan;
            int ff = i;
            do {
                vis[ff] = 1;
                huan.push_back(ff);
                ff = fa[ff];
            } while(ff != i);
            B.push_back(huan);
            posB.push_back(i);
        }
    }
    if(posA.size() != posB.size()) {
        cout << "No\n";
        return ;
    }
    int c = posA.size();
    for(int i = 0; i < c; i ++) {
        if(posA[i] != posB[i]) {
            cout << "No\n";
            return ;
        }
    }


    vector<int> q;
    bool ok = 1;
    for(int i = 0; i < c; i ++) {
        int l = 0, r = 0;
        while(A[i][l] != B[i][r] && r < B[i].size()) {
            r = r + 1;
        }
        if(r == B[i].size()) {
            cout << "No\n";
            return ;
        }

        for(int len = 0; len < B[i].size(); l ++, r = (r + 1) % B[i].size(), len ++) {
            if(A[i][l] != B[i][r]) {
                cout << "No\n";
                return ;
            }
        }
        if(l != r) {
            ok = 0;
        }
        q.push_back(B[i].size());
    }
    if(!ok) {
        for(int i = 0; i < q.size(); i ++) {
            for(int j = i + 1; j < q.size(); j ++) {
                if(__gcd(q[i], q[j]) != 1) {
                    cout << "No\n";
                }
            }
        }
    }
    cout << "Yes\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t --) {
        solve();
    }
}