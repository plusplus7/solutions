#include <bits/stdc++.h>

using namespace std;
int n;
int p[200005];
int x[200005];
int main(){

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", p+i);
            x[p[i]] = i;
        }
        int minx = -1, maxx = -1;
        for (int i=1; i<=n; i++) {
            if (minx == -1 || x[i] < minx) {
                minx = x[i];
            }
            if (maxx == -1 || x[i] > maxx) {
                maxx = x[i];
            }
            if (maxx - minx + 1 == i) {
                printf("1");
            }
            else {
                printf("0");
            }
        }
        printf("\n");
    }
}
