#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int add(int a,int b){ return a + b < mod ? a + b : a + b - mod;}
int sub(int a,int b){ return a < b ? mod + a - b : a - b;}
int mul(int a,int b){ return 1ll * a * b % mod; }

vector<vector<pair<int, ll>>> G(26);
int n;
vector<int> mp(26);
ll ress;
string expr;
ll qpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            (res *= x) %= mod;
        }
        (x *= x) %= mod;
        y >>= 1;
    }
    return res;
}
void init() {
    for(int i = 0; i < 26; i ++) {
        G[i].clear();
        mp[i] = INF;
    }
    ress = 0;
}
int cal(string s) {
    stack<int> stk;
    stack<char> op;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            int x = mp[s[i] - 'a'];
            while(op.size() && op.top() == '*') {
                (x *= stk.top()) %= mod;
                stk.pop();
                op.pop();
            }
            stk.push(x);
        } else if(s[i] >= '0' && s[i] <= '9') {
            int x = 0;
            for(int j = i; j < s.size() && s[j] >= '0' && s[j] <= '9'; j ++) {
                x = x * 10 + s[j] - '0';
                i = j;
            }
            while(op.size() && op.top() == '*') {
                (x *= stk.top()) %= mod;
                stk.pop();
                op.pop();
            }
            stk.push(x);
        } else if(s[i] == '(') {
            op.push('(');
        } else if(s[i] == '*') {
            op.push('*');
        } else if(s[i] == '+') {
            op.push('+');
        } else if(s[i] == '-') {
            op.push('-');
        } else if(s[i] == ')') {
            int x = 0;
            while (op.size()) {
                if(op.top() == '(') {
                    op.pop();
                    break;
                } else if(op.top() == '-') {
                    int x = stk.top(); stk.pop();
                    int y = stk.top(); stk.pop();
                    stk.push((y - x + mod) % mod);
                } else if(op.top() == '+') {
                    int x = stk.top(); stk.pop();
                    int y = stk.top(); stk.pop();
                    stk.push((y + x) % mod);
                }
                op.pop();
            }
            x = stk.top(); stk.pop();
            while(op.size() && op.top() == '*') {
                (x *= stk.top()) %= mod;
                stk.pop();
                op.pop();
            }
            stk.push(x);
        }
    }
    int Res = 0;
    while (op.size()) {
        if(op.top() == '-') {
            int x = stk.top(); stk.pop();
            int y = stk.top(); stk.pop();
            stk.push((y - x + mod) % mod);
        } else if(op.top() == '+') {
            int x = stk.top(); stk.pop();
            int y = stk.top(); stk.pop();
            stk.push((y + x) % mod);
        }
        op.pop();
    }
    Res = stk.top();
    return Res % mod;
}


char s[10000];
int expression(char*&s);
int token(char*&s){
    if(*s=='('){
        s++;
        int ret=expression(s);
        s++;
        return ret;
    }
    if('a'<=*s&&*s<='z')return mp[*s++-'a'];
    int ret=0;
    while('0'<=*s&&*s<='9'){
        ret=ret*10+*s++-'0';
    }
    return ret%mod;
}
int rank(char op){
    switch(op){
        case '-':return 1;
        case '+':return 1;
        case '*':return 0;
    }
    return 2;
}
int expression(char*&s){
    stack<int>svar;
    stack<char>sop;
    svar.push(token(s));
    while(true){
        char op=*s;
        if(!op||op==')')op='$';
        else s++;
        while(!sop.empty()&&::rank(sop.top())<=::rank(op)){
            int b=svar.top();
            svar.pop();
            int a=svar.top();
            svar.pop();
            switch(sop.top()){
                case '+':{
                    svar.push(add(a,b));
                    break;
                }
                case '-':{
                    svar.push(sub(a,b));
                    break;
                }
                case '*': {
                    svar.push(mul(a,b));
                    break;
                }
            }
            sop.pop();
        }
        if(op=='$')break;
        svar.push(token(s));
        sop.push(op);
    }
    return svar.top();
}

void dfs(int d, ll P) {
    if(d == 26) {
        char *_s = s;
        ll rec = expression(_s);
        (ress += (rec * P) % mod) %= mod;
        return ;
    }
    if(G[d].size()) {
        for(auto [x, p] : G[d]) {
            mp[d] = x;
            dfs(d + 1, (P * p) % mod);
        }
    } else {
        mp[d] = INF;
        dfs(d + 1,P % mod);
    }
}
// void check() {
//     cin >> expr;
//     cout << cal(expr);
// }
void solve() {
    init();
    cin >> n;
    for(int i = 0; i < n; i ++) {
        char x;
        int k;
        cin >> x >> k;
        for(int j = 0; j < k; j ++) {
            int val;
            string tp;
            cin >> val >> tp;
            ll p = 0;
            for(int i = 0; i < tp.size(); i ++) {
                if(i == 1) continue;
                p = p * 10 + tp[i] - '0';
            }
            (p *= qpow(1000000, mod - 2)) %= mod;
            G[x - 'a'].push_back({val, p});
        }
    }
    // cin >> expr;
    scanf("%s",s);
    dfs(0, 1);
    cout << (ress % mod + mod) % mod << '\n';
}
signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
        // check();
    }
    return 0;
}