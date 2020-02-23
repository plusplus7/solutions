#include <bits/stdc++.h>
using namespace std;
#define MD 1000000000
vector< pair<int, int> > st;
int n, sx, sy;
int between(int a, int b, int c) {
    int ta = a, tb = b;
    if (a > b) {
        ta = b;
        tb = a;
    }
    return ta <= c && c <= tb;
}

int main() {
    scanf("%d%d%d", &n, &sx, &sy);
    for (int i=0; i<n; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        st.push_back(make_pair(t1, t2));
    }
    int dir[8][2] = { {1, 0},
                      {0, 1},
                      {-1, 0},
                      {0, -1},
                      {1, 1},
                      {1, -1},
                      {-1, 1},
                      {-1, -1} };

    int ans = -1;
    int ax = 0;
    int ay = 0;
    for (int d=0; d<8; d++) {
        int dx = sx + dir[d][0];
        int dy = sy + dir[d][1];
        int tmax = 0;

        if (dx < 0 || dx > MD || dy < 0 || dy > MD) continue;

        for (int i=0; i<n; i++) {
            int tx = st[i].first, ty = st[i].second;
            if (between(tx, sx, dx) && between(ty, sy, dy)) {
                tmax ++;
            }
        }
       // printf("%d\n%d %d\n", tmax, dx, dy);
        if (tmax > ans) {
            ans = tmax;
            ax = dx;
            ay = dy;
        }
    }
    printf("%d\n%d %d\n", ans, ax, ay);
}
