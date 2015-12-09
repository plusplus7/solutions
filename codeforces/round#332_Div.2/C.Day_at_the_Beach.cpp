#include <cstdio>

#define MAXN 1000006

int a[MAXN];
int vm[MAXN];
int vx[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", a+i);
    }
    int ans = 0;
    int tmin = a[n-1];
    vm[n-1] = a[n-1];
    for (int i=n-2; i>=0; i--) {
        if (tmin >= a[i]) {
            tmin = a[i];
        }
        vm[i] = tmin;

    }
    int tmax = a[0];
    vx[0] = a[0];
    for (int i=1; i<n; i++) {
        if (tmax <= a[i]) {
            tmax = a[i];
        }
        vx[i] = tmax;
    }
    for (int i=0; i<n-1; i++) {
        if (vx[i] <= vm[i+1]) {
            ans++;
        }
    }
    /*   printf("\n");
         for (int i=0; i<n; i++) {
         printf("%d ", vm[i]);
         }
         printf("\n");
         for (int i=0; i<n; i++) {
         printf("%d ", vx[i]);
         }
         printf("\n");*/
    printf("%d\n", ans+1);
}
