#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int mp[20][20];
int res[20][20], now[20][20], tempres[20][20];
int n, m;
vector<int> op;
int maxcnt = INF;
const int dx[5] = {0, 0, 0, 1, -1}, dy[5] = {0, 1,- 1, 0, 0};
void get(int x, int y) {
    for(int i = 0; i < 5; i ++) {
        int X = x + dx[i], Y = y + dy[i];
        if(X >= 0 || X < n || Y >= 0 || Y < m) {
            now[X][Y] ++;
        }
    }
    return ;
}
void dfs(int step) {
    if(step == m) {
        int cnt = 0;
        memset(now, 0, sizeof now);
        memset(tempres, 0, sizeof tempres);
        for(int i = 0; i < m; i ++) {
            tempres[0][i] = op[i];
            if(op[i] == 1) {
                cnt ++;
                get(0, i);
            }
        }
        for(int i = 1; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if((now[i - 1][j] + mp[i - 1][j]) % 2 == 1) {
                    tempres[i][j] ++;
                    get(i, j);
                    cnt ++;
                }
            }
        }
        bool ok = 1;
        for(int i = 0; i < m; i ++) {
            if((mp[n - 1][i] + now[n - 1][i]) % 2) {
                ok = 0;
            }
        }
        if(ok) {
            if(cnt < maxcnt) {
                maxcnt = cnt;
                for(int i = 0; i < n; i ++) {
                    for(int j = 0; j < m; j ++) {
                        res[i][j] = tempres[i][j];
                    }
                }
            }
        }
        return;
    }
    op.push_back(0);
    dfs(step + 1);
    op.back() = 1;
    dfs(step + 1);
    op.pop_back();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        for(int j = 0 ; j < m ;j ++) {
            cin >> mp[i][j];
        }
    }
    dfs(0);
    if(maxcnt == INF) {
        cout << "IMPOSSIBLE\n";
    } else {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                cout << res[i][j] << ' ';
            }
            cout <<'\n';
        }
    }
    return 0;
}