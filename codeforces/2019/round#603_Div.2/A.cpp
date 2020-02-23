#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >>T;
    while (T--) {
        int a[3];
        for (int i=0; i<3; i++)
        {
            cin >> a[i];
        }
        sort(a, a+3);

        int t = a[2] - a[1], ans = 0;
        if (t >= a[0]) {
            ans += a[0];
            a[2] -= a[0];
            ans += a[1];
        } else {
            ans += t;
            a[0] -= t;
            ans += a[0];
            ans += a[1] - (a[0]+1)/2;
        }
        cout << ans << endl;
    }
    return 0;
}
