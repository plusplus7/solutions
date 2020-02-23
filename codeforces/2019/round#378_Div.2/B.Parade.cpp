#include "bits/stdc++.h"

using namespace std;
int n;
int l[100006], r[100006];
int main() {
    scanf("%d", &n);
    int L = 0, R = 0;
    for (int i=1; i<=n; i++) {
        scanf("%d%d", l+i, r+i);
        L = L + l[i];
        R = R + r[i];
    }
    int ans = abs(L-R);
    int idx = 0;
    for (int i=1; i<=n; i++) {
        int tl = L, tr = R;
        tl = tl - l[i] + r[i];
        tr = tr - r[i] + l[i];
        int tans = abs(tr-tl);
        if (tans > ans) {
            idx = i;
            ans = tans;
        }
    }
    printf("%d\n", idx);
}
