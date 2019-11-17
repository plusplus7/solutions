#include <bits/stdc++.h>

using namespace std;

int a[200005], d[200005];
long long s[200005], ans[200005];
int main()
{
    int m, n;
    cin >> n >>m;
    for (int i=0; i<n; i++) {
        d[i] = 1;
        cin >> a[i];

    }

    sort(a, a+n);
    for (int i=0; i<n; i++) {
      if (i > 0) {
            s[i] = s[i-1] + a[i];
        } else {
            s[i] =  a[i];
        }

    }
    for (int i=0; i<n; i++) {
        if (i < m) {
            ans[i] = s[i];
            d[i] = 1;
        } else {
            ans [i] = ans[i-m]+s[i];
            d[i] = d[i-m]+1;
        }
        cout << ans[i] <<" ";
    }
    return 0;
}
