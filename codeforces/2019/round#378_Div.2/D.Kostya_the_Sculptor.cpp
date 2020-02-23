#include "bits/stdc++.h"

using namespace std;

int n;
struct T {
    int a;
    int b;
    int c;
    int num;
};
T a[200007];

int _min(int a, int b) {
    return a > b ? b :a ;
}

bool cmp(T a, T b) {
    if (a.c < b.c) {
        return false;
    } else if (a.c > b.c) {
        return true;
    } else {
        if (a.b < b.b) {
            return false;
        } else if (a.b > b.b) {
            return true;
        } else {
            if (a.a <= b.a) {
                return false;
            } else {
                return true;
            }
        }
    }
}

int main() {
    int ans = -1;
    int pick = 1;
    int p1 = 0, p2 = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int b[3];
        scanf("%d%d%d", b, b+1, b+2);
        sort(b, b+3);
        a[i].num = i+1;
        a[i].a = b[0];
        a[i].b = b[1];
        a[i].c = b[2];
        if (ans < a[i].a) {
            ans = a[i].a;
            pick = 1;
            p1 = i+1;
        }
    }
    {
        sort(a, a+n, cmp);
        int t2 = -1, t1 = -1;
        for (int i=0; i<n-1; i++) {
            if (a[i].c == a[i+1].c && a[i].b == a[i+1].b) {
                if (a[i].c == t2 && a[i].b == t1) {
                    continue;
                } else {
                    int ca = a[i].c;
                    int cb = a[i].b;
                    int cc = a[i].a + a[i+1].a;
                    int dd = _min(ca, _min(cb, cc));
                    if (ans < dd) {
                        ans = dd;
                        pick = 2;
                        p1 = a[i].num;
                        p2 = a[i+1].num;
                    }
                    t2 = a[i].c;
                    t1 = a[i].b;
                }
            }
        }
    }
    printf("%d\n", pick);
    if (pick == 1) {
        printf("%d\n", p1);
    } else {
        printf("%d %d\n", p1, p2);
    }
    return 0;
}
