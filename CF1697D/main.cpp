#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
int main() {
    int n;
    cin >> n;
    string res;
    vector<pair<int, char>> pla;
    int cnt = 1;
    for(int i = 1; i <= n; i ++) {
        if(i == 1) {
            cout << "? 1 1" << '\n';
            char x;
            cin >> x;
            res += x;
            pla.push_back({1, x});
        } else {
            cout << "? 2 1 " << i << '\n';
            int c;
            cin >> c;
            if(c > cnt) {
                cnt = c;
                cout << "? 1 " << i << '\n';
                char x;
                cin >> x;
                res += x;
                pla.push_back({i, x});
            } else {
                sort(pla.begin(), pla.end());
                int l = 0, r = pla.size() - 1;
                while(l < r) {
                    int mid = l + r + 1 >> 1;
                    cout << "? 2 " << pla[mid].first << " " << i << endl;
                    int ty; cin >> ty;
                    if(ty == pla.size() - (mid + 1) + 1) l = mid;
                    else r= mid - 1;
                }
                pla[l].first = i; res += pla[l].second;
            }
        }
    }
    cout << "! " << res << '\n';
}