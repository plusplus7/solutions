#include <cstdio>
#include <cstring>

#define MAXN 100006
int f[MAXN], b[MAXN];
int a[MAXN];

int vf[MAXN];
int vb[MAXN];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof(a));
    memset(vf, 0, sizeof(vf));
    memset(vb, 0, sizeof(vb));
    int mul = 0;
    for (int i=1; i<=n; i++) {
        int t;
        scanf("%d", &t);
        vf[t]++;
        vb[t] = i;
    }
    int amb = 0, imp = 0;
    for (int i=1; i<=m; i++) {
        scanf("%d", b+i);
        if (vf[b[i]] > 1) {
            amb++;
        } else if (vf[b[i]] == 0){
            imp++;
        }
    }
    if (imp) {
        printf("Impossible\n");
        return 0;
    }
    if (amb) {
        printf("Ambiguity\n");
        return 0;
    }
    for (int i=1; i<=m; i++) {
        a[i] = vb[b[i]];
    }
    printf("Possible\n");
    for (int i=1; i<m; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[m]);
    return 0;
}
