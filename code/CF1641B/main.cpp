#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i< n; i ++) {
        cin >> a[i];
    }
    vector<PII> ins;
    vector<int> lens;
    while(a.size()) {
        int i = a.size() - 1;
        int j = i - 1;
        while(j >= 0 && a[i] != a[j]) {
            j --;
        }
        if(j == - 1) {
            cout << "-1\n";
            return ;
        }
        for(int k = 0; k < i - j - 1; k ++) {
            ins.emplace_back(j + k, a[i - 1 - k]);
        }
        lens.push_back(2 * (i - j));
        reverse(a.begin() + j + 1, a.begin() + i);
        a.pop_back();
        a.erase(a.begin() + j);
    }
    reverse(lens.begin(), lens.end());
    cout << (int)ins.size() << '\n';
    for(auto &[p, c] : ins) {
        cout << p << ' ' << c << '\n';
    }
    cout << lens.size() << '\n';
    for(int i = 0; i < (int)lens.size(); i ++) {
        cout << lens[i] << "\n";
    }
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