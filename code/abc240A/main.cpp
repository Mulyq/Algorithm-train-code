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
    int a, b;
    cin >> a >> b;
    if(abs(a - b) == 1 || abs(a - b) == 9) cout << "Yes";
    else cout << "No";
    return 0;
}