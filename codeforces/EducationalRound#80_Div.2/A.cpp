#include <bits/stdc++.h>
using namespace std;

bool check(int x, int n, int d) {
   // cout << x <<' ' << n << endl;
   // cout << x + ceil((float)d / ((float)x + 1.0f)) << endl;
    return (x + ceil((float)d / ((float)x + 1.0f))) <= n;
}
int main() {
    int cas;
    scanf("%d", &cas);

    while (cas--) {
        int n, d;
        cin >> n >> d;
        int x = (n-1)/2, x1 = x-1, x2 = x+1;
        if (check(x,n,d) ||check(x1,n,d) || check(x2,n,d)) {

            cout << "YES" << endl;
        } else {
            cout << "NO"<<endl;
        }
    }
}
