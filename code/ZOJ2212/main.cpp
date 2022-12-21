#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<int> mp(3010);

    string op;
    while(cin >> op) {
        if(op == "#") {
            break;
        }
        int Q, P;
        cin >> Q >> P;
        mp[Q] = P;
        q.push({P, Q});
    }
    int k;
    cin >> k;
    while(k --) {
        PII temp = q.top();
        q.pop();
        cout << temp.second << '\n';
        temp.first += mp[temp.second];
        q.push(temp);
    }
    return 0;
}