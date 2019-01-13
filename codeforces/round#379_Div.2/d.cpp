#include <cstdio>
#include <cstring>

using namespace std;

int mini(int a, int b) {
    return a > b?b:a;
}
int maxi(int a, int b) {
    return a < b?b:a;
}

char rr[500005];
int main() {
    int n;
    int x0, y0;
    int m[8];
    int x[8];
    int y[8];
    memset(m, -1, sizeof(m));
    scanf("%d", &n);
    int tx,ty;
    scanf("%d%d", &tx, &ty);
    x0 = ty;
    y0 = -tx;
    for (int i=0; i<n; i++) {
        int t1, t2, t3, t4;
        getchar();
        scanf("%c%d%d", &rr[i], &t3, &t4);
        t1 = t4;
        t2 = -t3;
        if (t1 == x0) {
            if (t2 > y0) {
                if (m[0] == -1) {
                    m[0] = i;
                    x[0] = t1;
                    y[0] = t2;
                } else {
                    if (t2 > y[0]) {
                        y[0] = t2;
                        m[0] = i;
                    }
                }
            } else {
                if (m[4] == -1) {
                    m[4] = i;
                    x[4] = t1;
                    y[4] = t2;
                } else {
                    if (t2 < y[4]) {
                        y[4] = t2;
                        m[4] = i;
                    }
                }
            }
        }
        if (t2 == y0) {
            if (t1 > x0) {
                if (m[2] == -1) {
                    m[2] = i;
                    x[2] = t1;
                    y[2] = t2;
                } else {
                    if (x[2] > t1) {
                        x[2] = t1;
                        m[2] = i;
                    }
                }
            } else {
                if (m[6] == -1) {
                    m[6] = i;
                    x[6] = t1;
                    y[6] = t2;
                } else {
                    if (x[6] < t1) {
                        x[6] = t1;
                        m[6] = i;
                    }
                }
            }
        }
        if (t1 > x0 && t2 > y0 && t1-x0 == t2-y0) {
            if (m[1] == -1) {
                m[1] = i;
                x[1] = t1;
                y[1] = t2;
            } else {
                if (t1-x0 < x[1]-x0) {
                    x[1] = t1;
                    y[1] = t2;
                    m[1] = i;
                }
            }
        }
        if (t1 > x0 && t2 < y0 && t1-x0 == y0-t2) {
            if (m[3] == -1) {
                m[3] = 1;
                x[3] = t1;
                y[3] = t2;
            } else {
                if (t1-x0 < x[3]-x0) {
                    x[3] = t1;
                    y[3] = t2;
                    m[3] = i;
                }
            }
        }
        if (t1 < x0 && t2 < y0 && x0-t1 == y0-t2) {
            if (m[5] == -1) {
                m[5] = 1;
                x[5] = t1;
                y[5] = t2;
            } else {
                if (x0-t1 < x0-x[5]) {
                    x[5] = t1;
                    y[5] = t2;
                    m[5] = i;
                }
            }
        }
        if (t1 < x0 && t2 > y0 && x0-t1 == t2-y0) {
            if (m[7] == -1) {
                m[7] = 1;
                x[7] = t1;
                y[7] = t2;
            } else {
                if (x0-t1 < x0-x[7]) {
                    x[7] = t1;
                    y[7] = t2;
                    m[7] = i;
                }
            }
        }
    }
    bool f = false;
    for (int i=0; i<8; i++) {
        if (m[i] == -1) {
            continue;
        }
        char c = rr[m[i]];
        if ((i == 0 || i == 4 || i == 6 || i == 2) && (c == 'R' || c == 'Q')) {
            f = true;
        }
        if ((i == 1 || i == 3 || i == 5 || i == 7) && (c == 'B' || c == 'Q')) {
            f = true;
        }
    }
    if (f) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
