#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e5 + 10, mod = 998244353;
int n, m, BS;
ll a[MAXN];
ll _1[MAXN], _2[MAXN];
struct BLOCK {
    int l, r;
    ll ex;
    vector<ll> B;
    vector<int> mp;
    BLOCK(int s) {
        B.resize(s);
        ex = 0;
    }
    BLOCK(int _l, int _r) {
        ex = 0;
        l = _l, r = _r;
        int s = r - l + 1;
        B.resize(s);
        mp.resize(s);
        for(int i = l; i <= r; i ++) {
            mp[i - l] = i;
        }
        sort(mp.begin(), mp.end(), [&] (int x, int y)  {
            return a[x] < a[y];
        });
        for(int i = 0; i < s; i ++) {
            B[i] = a[mp[i]];
        }
    }
// ----------------------------------------
    void rebuild(int s, int t, int k) {
        vector<int> _1, _2;
        for(int i = 0; i < mp.size(); i ++) {
            int x = mp[i];
            if(x >= s && x <= t) {
                _1.push_back(x);
            } else {
                _2.push_back(x);
            }
        }
        for(int i : _1) a[i] += k;
        int i = 0, j = 0, c = 0;
        while(i < _1.size() && j < _2.size()) {
            if(a[_1[i]] < a[_2[j]]) mp[c ++] = _1[i ++];
            else mp[c ++] = _2[j ++];
        }
        while(i < _1.size()) mp[c ++] = _1[i ++];
        while(j < _2.size()) mp[c ++] = _2[j ++];
        for(int i = 0; i < mp.size(); i ++) B[i] = a[mp[i]];
    }
// ----------------------------------------
};
vector<BLOCK> block;
void add(int l, int r, int k) {
    int lb = l / BS, rb = r / BS;
    if(lb == rb) {
        block[lb].rebuild(l, r, k);
    } else {
        block[lb].rebuild(l, block[lb].r, k);
        block[rb].rebuild(block[rb].l, r, k);
        for(int i = lb + 1; i < rb; i ++) {
            block[i].ex += k;
        }
    }
}
ll query(int l, int r, int k) {
    int lb = l / BS, rb = r / BS;
    if(lb == rb) {
        int c = 0;
        for(int i : block[lb].mp) {
            if(i >= l && i <= r) c ++;
            if(c == k) return a[i] + block[lb].ex;
        }
    } else {
        BLOCK _ex(block[lb].r - l + 1 + r - block[rb].l + 1);



// -------------------------------------------

        int c = 0;
        for(int i : block[lb].mp) {
            if(i >= l) _ex.B[c ++] = a[i] + block[lb].ex;
        }
        for(int i : block[rb].mp) {
            if(i <= r) _ex.B[c ++] = a[i] + block[rb].ex;
        }
        sort(_ex.B.begin(), _ex.B.end());

// -------------------------------------------



        ll L = 1e18, R = -1e18;
        L = min(L, _ex.B[0]);
        R = max(R, _ex.B.back());
        for(int i = lb + 1; i < rb; i ++) {
            L = min(L, block[i].B[0] + block[i].ex);
            R = max(R, block[i].B.back() + block[i].ex);
        }
        L --, R ++;
        while(R > L + 1) {
            ll M = L + R  >> 1;
            int cnt = 0;
            cnt += lower_bound(_ex.B.begin(), _ex.B.end(), M) - _ex.B.begin();
            for(int i = lb + 1; i < rb; i ++) {
                cnt += lower_bound(block[i].B.begin(), block[i].B.end(), M - block[i].ex) - block[i].B.begin();
            }
            if(cnt >= k) R = M;
            else L = M;
        }
        return R - 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    BS = sqrt(n) + 80;
    for(int i = 0; 1ll * i * BS < n; i ++) {
        int l = i * BS, r = min(n - 1, (i + 1) * BS - 1);
        block.push_back(BLOCK(l, r));
    }
    while(m --) {
        int op, l, r, k;
        cin >> op >> l >> r >> k;
        l --, r --;
        if(op == 1) {
            if(r - l + 1 < k) {
                cout << "-1\n";
            } else {
                cout << query(l, r, k) << '\n';
            }
        } else {
            add(l, r, k);
        }
    }
}