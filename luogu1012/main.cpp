#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n;
    cin >> n;
    vector<string> all(n);
    for(int i = 0; i< n;i ++) {
        cin >> all[i];
    }
    sort(all.begin(), all.end(), [&] (string a, string b) {
        return a + b > b + a;
    });
    for(int i = 0; i < n; i ++) {
        cout << all[i];
    }
    return 0;
}