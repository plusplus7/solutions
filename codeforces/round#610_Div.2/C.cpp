#include <bits/stdc++.h>
using namespace std;

int n, T, a, b;
struct crsc {
    int s;
    int t;
};
bool cmp(crsc &a, crsc &b) {
    return a.t < b.t;
}

crsc crs[200005];
long long sb[200005];

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d%d", &n, &T, &a, &b);
        for (int i=0; i<n; i++){
            int t;
            scanf("%d", &t);
            if (t == 0) {
                crs[i].s = a;
            } else {
                crs[i].s = b;
            }
        }
        for (int i=0; i<n; i++){
            scanf("%d", &(crs[i].t));
        }

        sort(crs, crs+n, cmp);

        for (int i=0; i<n; i++){
            sb[i] = i == 0 ? crs[i].s : ((long long)crs[i].s + sb[i - 1]);
           // cout << sb[i] << "-" << crs[i].t << " " ;
        }
//        cout << endl;

        int ans = 0;
        int s = 0;
        for (int i=1; i<n; i++) {
            int tm = crs[i].t-1;
            int x = upper_bound(sb, sb+n, tm) - sb;
            if (x-1 >= i-1) {
                ans = max(x, ans);
            }
            tm = crs[i].t;
            x = upper_bound(sb, sb+n, tm) - sb;
            if (x-1 >= i) {
                ans = max(x, ans);
            }
 //           cout <<i <<" "<< tm << " " << x << " " << ans << endl;
        }
        int xx = upper_bound(sb, sb + n, T) - sb;
        if (xx >= n)
        {
            ans = max(xx, ans);
        }
        printf("%d\n", ans);
    }
}
