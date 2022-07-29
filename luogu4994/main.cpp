#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    vector<ll> feb = {0,1};
    int m = 1;
    cin >> m;
    while((feb.back()) % m != 0 || feb[feb.size() - 2] % m != 1) {
        feb.push_back(feb[feb.size() - 1] % m + feb[feb.size() - 2] % m);
    }
    cout << feb.size() - 1 << '\n';
    return 0;
}