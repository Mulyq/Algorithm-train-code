#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<PII> rec(1, {0, 0});
    vector<vector<int>> res(n + 1, vector<int> (n + 1));
    res[1][n + 1 >> 1] = 1;
    rec.push_back({1, n + 1 >> 1});
    for(int i = 2; i <= n * n; i ++) {
        if(rec[i - 1].first == 1) {
            if(rec[i - 1].second != n) {
                res[n][rec[i - 1].second + 1] = i;
                rec.push_back({n, rec[i - 1].second + 1});
            } else {
                res[rec[i - 1].first + 1][rec[i - 1].second] = i;
                rec.push_back({rec[i - 1].first + 1, rec[i - 1].second});
            }
        } else if(rec[i - 1].second == n) {
            if(rec[i - 1].first != 1) {
                res[rec[i - 1].first - 1][1] = i;
                rec.push_back({rec[i - 1].first - 1, 1});
            }
        } else {
            int row = rec[i - 1].first, col = rec[i - 1].second;
            if(res[row - 1][col + 1] == 0) {
                res[row - 1][col + 1] = i;
                rec.push_back({row - 1, col + 1});
            } else {
                res[row + 1][col] = i;
                rec.push_back({row + 1, col});
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n ;j ++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}