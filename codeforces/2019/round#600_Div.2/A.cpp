/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int n, T, d;
int a[100005],b[100005];
int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        d = 0;
        for (int i=1; i<=n; i++) {
            cin >> b[i];
            a[i] -= b[i];
            d = a[i]!=0?a[i]:d;
        }
        a[n+1] = 0;
        int flag = 0;

        for (int i=1; i<=n; i++) {
            if (a[i] > 0) {
                flag = 100;
                break;
            }
            if (a[i] != 0 && a[i] != d) {
                flag = 100;
                break;
            }
        }
        for (int i=1; i<=n+1; i++) {
            if (a[i-1] < 0 && a[i] == 0) {
                flag ++;
            }
        }

        if (flag < 2) {
            cout << "YES" << endl;
        } else {
            cout <<"NO" << endl;
        }

    }
    return 0;
}
