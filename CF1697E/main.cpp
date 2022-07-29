#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<PII> node(n);
    for(auto & [a, b] : node) {
        cin >> a >> b;
    }
    struct dis {
        int a, b;
        ll d;
        bool operator< (const dis &a) const {
            return d < a.d;
        }
    };
    vector<dis> D;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i != j) {
                D.push_back({i, j, abs(node[i].first - node[j].first) + abs(node[i].second - node[j].second)});
            }
        }
    }
    ll res = 1;
    sort(D.begin(), D.end());
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < i; j ++) {
            
        }
    }
}