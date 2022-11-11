#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e5 + 9, mod = 998244353;
void read() {}
template<typename T,typename... Ts>
inline void read(T &arg,Ts&... args) {
    T x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
    while(isdigit(c)){x = (x << 3) +(x << 1) + (c - '0');c = getchar();}
    arg = x * f;
    read(args...);
}
int n, m, BS;
ll a[MAXN];
int _1[MAXN], _2[MAXN], t1, t2;
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
        for(int i = l; i <= r; ++ i) {
            mp[i - l] = i;
        }
        sort(mp.begin(), mp.end(), [&] (int x, int y)  {
            return a[x] < a[y];
        });
        for(int i = 0; i < s; i ++) {
            B[i] = a[mp[i]];
        }
    }
    void rebuild(int s, int t, int k) {
        t1 = t2 = 0;
        for(int i = 0; i < mp.size(); ++ i) {
            int x = mp[i];
            if(x >= s && x <= t) _1[t1 ++] = x;
            else _2[t2 ++] = x;
        }
        for(int i = 0; i < t1; ++ i) a[_1[i]] += k;
        int  i = 0, j = 0, c = 0;
        while(i < t1 && j < t2) {
            if(a[_1[i]] < a[_2[j]]) mp[c ++] = _1[i ++];
            else mp[c ++] = _2[j ++];
        }
        while(i < t1) mp[c ++] = _1[i ++];
        while(j < t2) mp[c ++] = _2[j ++];
        for(int i = 0; i < mp.size(); i ++) B[i] = a[mp[i]];
    }
};
vector<BLOCK> block;
inline void add(int l, int r, int k) {
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
inline ll query(int l, int r, int k) {
    int lb = l / BS, rb = r / BS;
    if(lb == rb) {
        int c = 0;
        for(int i : block[lb].mp) {
            if(i >= l && i <= r) c ++;
            if(c == k) return a[i] + block[lb].ex;
        }
    } else {
        BLOCK _ex(block[lb].r - l + 1 + r - block[rb].l + 1);
        t1 = t2 = 0;
        // B
        for(int i : block[lb].mp) {
            if(i >= l) _1[t1 ++] = a[i] + block[lb].ex;
        }
        // B
        for(int i : block[rb].mp) {
            if(i <= r) _2[t2 ++] = a[i] + block[rb].ex;
        }
        int c = 0, i = 0, j = 0;
        // 2B
        while(i < t1 && j < t2) {
            if(_1[i] < _2[j]) _ex.B[c ++] = _1[i ++];
            else _ex.B[c ++] = _2[j ++];
        }
        while(i < t1) _ex.B[c ++] = _1[i ++];
        while(j < t2) _ex.B[c ++] = _2[j ++];
        ll L = 1e18, R = -1e18;
        L = min(L, _ex.B[0]);
        R = max(R, _ex.B.back());
        // n / B
        for(int i = lb + 1; i < rb; ++ i) {
            L = min(L, block[i].B[0] + block[i].ex);
            R = max(R, block[i].B.back() + block[i].ex);
        }
        L --, R ++;
        // log w * (n / B) * log B
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
    read(n, m);
    for(int i = 0; i < n; ++ i) {
        read(a[i]);
    }
    BS = 912;
    for(int i = 0; 1ll * i * BS < n; ++ i) {
        int l = i * BS, r = min(n - 1, (i + 1) * BS - 1);
        block.push_back(BLOCK(l, r));
    }
    while(m --) {
        int op, l, r, k;
        read(op, l, r, k);
        l --, r --;
        if(op == 1) {
            if(r - l + 1 < k) {
                cout << "-1\n";
            } else {
                printf("%lld\n", query(l, r, k));
            }
        } else {
            add(l, r, k);
        }
    }
}