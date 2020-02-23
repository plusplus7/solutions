#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a,b,c,r;
        cin >>a >>b>>c>>r;
        if (b < a) {
            int t = a;
            a = b;
            b = t;
        }
        int ra = c-r, rb = c+r, ans = 0;
        if (ra > b) {
            ans = b-a;
        }
        if (rb < a) {
            ans = b-a;
        }

        if (ra >= a && ra <= b) {
            ans += ra - a;
        }
        if (rb <= b && rb >= a) {
            ans += b-rb;
        }
        cout << ans << endl;
    }
    return 0;
}
