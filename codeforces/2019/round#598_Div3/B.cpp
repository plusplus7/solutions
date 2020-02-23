#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int a[105];
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int steps = n-1, curx = 0, cur = 1;
        while (steps > 0 && cur <= n&& curx < n) {

            if (a[curx] == cur) {
                curx ++;
                cur++;
                continue;
            }
            if (a[curx] < cur) {
                curx ++;

                continue;
            }
            int t;
            for (int i=curx+1; i<n; i++) {
                if (a[i] == cur) {
                    t = i;
                }
            }
            for (int i=t-1; i>=curx; i--) {
                int tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                steps--;
            }
            curx = t;
            cur++;

        }

        for (int i=0; i<n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
     }
}
