#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
const int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2}, dy[8] = {-2, -2, -1, 1, 2, 2, -1, 1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<PII> v;
    for(int i = 0; i < 8 ; i ++) {
        int X = x1 + dx[i];
        int Y = y1 + dy[i];
        v.push_back({X, Y});
    }
    for(int i = 0; i < 8 ; i ++) {
        int X = x2 + dx[i];
        int Y = y2 + dy[i];
        for(auto x : v) {
            if(X == x.first && Y == x.second) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}