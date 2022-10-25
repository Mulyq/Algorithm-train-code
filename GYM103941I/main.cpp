#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
PII t[3][10][10];   // 0  X, 1  Y ,2  Z; first 位置， second 编号
int v[510];         // 0 未上电梯，1在x电梯上，2在y电梯上，3在z电梯上
struct P {
    int tim;        // 出现时间
    int x, y, z;    // 当前位置
    int tx, ty, tz; // 目标位置
} p[60]; 
int n, m, h, q, k;

void work() {
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= h; j ++) {
            if(t[0][i][j].first > 0) {
                t[0][i][j].first %= n;
                t[0][i][j].first ++;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= h; j ++) {
            if(t[1][i][j].first >= 0) {
                t[1][i][j].first %= m;
                t[1][i][j].first ++;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(t[2][i][j].first >= 0) {
                t[2][i][j].first %= h;
                t[2][i][j].first ++;
            }
        }
    }
}

struct RES {
    int tt;
    int p;
    int io;
    int xl;
    int x, y, z;
    const bool operator < (const RES& a) const {
        if(tt != a.tt) return tt < a.tt;
        if(xl != a.xl) return xl < a.xl;
        if(io != a.io) return io < a.io;
        if(p != a.p) return p < a.p;
    }
};
vector<RES> res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> h >> k;
    for(int i = 0; i < k; i ++) {
        int type, ex, ey, ez;
        cin >> type >> ex >> ey >> ez;
        if(type == 0) {
            t[type][ey][ez].first = ex;
            t[type][ey][ez].second = i;
        } else if(type == 1) {
            t[type][ex][ez].first = ey;
            t[type][ex][ez].second = i;
        } else {
            t[type][ex][ey].first = ez;
            t[type][ex][ey].second = i;
        }
    }
    cin >> q;
    for(int i = 0; i < q; i ++) {
        auto &[tim, x, y, z, tx, ty, tz] = p[i];
        cin >> tim >> x >> y >> z >> tx >> ty >> tz;
    }
    int tt = 0; // 当前时间戳
    bool ok = 0;
    do {
        ok = 0;
        for(int i = 0; i < q; i ++) {
            if(p[i].tim <= tt) {
                // 未进电梯
                if(v[i] == 0) {
                    if(p[i].x != p[i].tx) {
                        ok = 1;
                        if(t[0][p[i].y][p[i].z].first == p[i].x) {
                            res.push_back({tt, i + 1, 1 , t[0][p[i].y][p[i].z].second + 1, p[i].x, p[i].y, p[i].z});
                            v[i] = 1;
                            p[i].x %= n;
                            p[i].x ++;
                        }
                    } else if(p[i].y != p[i].ty) {
                        ok = 1;
                        if(t[1][p[i].x][p[i].z].first == p[i].y) {
                            res.push_back({tt, i + 1, 1 , t[1][p[i].x][p[i].z].second + 1, p[i].x, p[i].y, p[i].z});
                            v[i] = 2;
                            p[i].y %= m;
                            p[i].y ++;
                        }
                    } else if(p[i].z != p[i].tz) {
                        ok = 1;
                        if(t[2][p[i].x][p[i].y].first == p[i].z) {
                            res.push_back({tt, i + 1, 1 , t[2][p[i].x][p[i].y].second + 1, p[i].x, p[i].y, p[i].z});
                            v[i] = 3;
                            p[i].z %= h;
                            p[i].z ++;
                        }
                    }
                } else if(v[i] == 1) {
                    ok = 1;
                    if(p[i].x == p[i].tx) {
                        res.push_back({tt, i + 1, 0, t[0][p[i].y][p[i].z].second + 1, p[i].x, p[i].y, p[i].z});
                        v[i] = 0;
                    } else {
                        p[i].x %= n;
                        p[i].x ++;
                    }
                } else if(v[i] == 2) {
                    ok = 1;
                    if(p[i].y == p[i].ty) {
                        res.push_back({tt, i + 1, 0, t[1][p[i].x][p[i].z].second + 1, p[i].x, p[i].y, p[i].z});
                        v[i] = 0;
                    } else {
                        p[i].y %= m;
                        p[i].y ++;
                    }
                } else if(v[i] == 3) {
                    ok = 1;
                    if(p[i].z == p[i].tz) {
                        res.push_back({tt, i + 1, 0, t[2][p[i].x][p[i].y].second + 1, p[i].x, p[i].y, p[i].z});
                        v[i] = 0;
                    } else {
                        p[i].z %= h;
                        p[i].z ++;
                    }
                }
            } else {
                ok = 1;
            }
        }
        work();
        tt ++;
    } while (ok);
    sort(res.begin(), res.end());
    for(auto i : res) {
        // [time] Person person_id IN / OUT Elevator elevator_id at (x, y, z);
        if(i.io == 1) {
            cout << "[" << i.tt << "s] Person " << i.p << " IN Elevator " << i.xl << " at (" << i.x << ", " << i.y << ", " << i.z << ")\n";
        } else {
            cout << "[" << i.tt << "s] Person " << i.p << " OUT Elevator " << i.xl << " at (" << i.x << ", " << i.y << ", " << i.z << ")\n";

        }
    }
}