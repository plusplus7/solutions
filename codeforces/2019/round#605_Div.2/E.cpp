
#include <bits/stdc++.h>
using namespace std;

int a[200005];
int v[200005];
int it[200005];
int n;
stack<int> ts;
int gao(int x)
{
    if (it[x] == 1) {
        return -1;
    }
    if (v[x] != -1) {
        return v[x];
    }

    int td[2] = {x-a[x], x+a[x]};
    int gx = -1;
    for (int i=0; i<2; i++) {
        int d = td[i];

        if (d >=0 && d < n) {
         //   printf("%d %d %d\n", a[d], a[x], (a[d]&1) != (a[x]&1));
            if ((a[d]&1) != (a[x]&1)) {
                return 1;
            } else {
                it[x] = 1;
                int go = gao(d);
                if (gx == -1 || go < gx) {
                    gx = go;
                }
                it[x] = 0;
            }
        }
    }
    if (gx == -1) {
        return gx;
    }
    return gx+1;
}

int main()
{

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", a+i);
    }

    memset(v, -1, sizeof(v));
    memset(it, 0, sizeof(it));
    for (int i=0; i<n; i++) {
        if (v[i] == -1) {
            v[i] = gao(i);
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
