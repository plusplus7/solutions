#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
map<int, int> v;
int main()
{

    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        v.clear();
        for (int i=0; i<n; i++) {
            scanf("%d", a+i);
            if ((a[i]&1) == 1)
                continue;
            int t = a[i], s = 0;
            while ((t&1) == 0) {
                t>>=1;
                s++;
            }
            if (v.count(t) != 0) {
                v[t] = max(v[t], s);
            } else {
                v[t] = s;
            }

        }
        int ans = 0;
        for (map<int, int>::iterator tv = v.begin(); tv != v.end(); tv++)
        {
            ans += tv->second;
        }
        printf("%d\n", ans);

    }
    return 0;
}
