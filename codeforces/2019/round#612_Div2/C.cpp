#include <bits/stdc++.h>

using namespace std;
int n;
int o, e;
int p[105];
int t[105];
bool gao(int l, int pr, int tl, int x, int xo, int xe) {
  /*  printf("\n\n");
    for (int i=0; i<n; i++) {
        printf("%d ", t[i]);
    }
    printf("\n\n");
    printf("%d %d %d %d %d %d\n", l, pr, tl, x, xo, xe);*/
    if (tl > l) {
        return false;
    }
    if (x == n) {
        return true;
    }

    if (p[x] == 0) {
        if (xo != 0) {
            t[x] = 1;
            if (gao(l, 1, tl+(pr==0), x + 1, xo - 1, xe)) {
                return true;
            }
            t[x] = -1;
        }
        if (xe != 0){
            t[x] = 0;
            if (gao(l, 0, tl+(pr==1), x + 1, xo, xe-1)) {
                return true;
            }
            t[x] = -1;
        }
    }
    else {
        t[x] = p[x]%2;
        if (gao(l, p[x]%2, tl+(p[x]%2 != pr && pr != -1), x + 1, xo, xe)) {
            return true;
        }
            t[x] = -1;
    }
    return false;
}

bool check(int l) {
    memset(t, -1, sizeof(t));
    return gao(l, -1, 0, 0, o, e);
}

int main() {

    scanf("%d", &n);
    o = (n+1)/2;
    e = n/2;
    for (int i=0; i<n; i++) {
        scanf("%d", p+i);
        if (p[i] == 0) continue;
        if (p[i]&1) {
            o--;
        } else {
            e--;
        }
    }
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    for (int i=1; i<100; i++) {
        if (check(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
}
