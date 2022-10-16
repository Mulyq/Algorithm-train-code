#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> pos(26);
    for(int i = 0; i < n; i ++) {
        pos[s[i] - 'a'].push_back(i);
    }
    for(int i = 0; i < 26; i ++) if(pos[i].size() >= 5) {
        int x1 = 4;
        for(int j = 0; j < 26; j ++) {
            int c = upper_bound(pos[j].begin(), pos[j].end(), pos[i][x1]) - pos[j].begin();
            if(pos[j].size() - c < 7) {
                continue;
            }
            int x2 = c + 6;
            for(int k = 0; k < 26; k ++) {
                int c = upper_bound(pos[k].begin(), pos[k].end(), pos[j][x2]) - pos[k].begin();
                if(pos[k].size() - c < 5) {
                    continue;
                }
                int x3 = c + 4;
                char x = 'a' + i, y = 'a' + j, z = 'a' + k;
                for(int t = 0; t < 5; t ++) {
                    cout << x;
                }
                for(int t = 0; t < 7; t ++) {
                    cout << y;
                }
                for(int t = 0; t < 5; t ++) {
                    cout << z;
                }
                cout << '\n';
                return 0;
            }

        }
    }
    cout << "none\n";
    return 0;
}