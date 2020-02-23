#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int a[105], in[105];
int n;
int v[105];
int ans = -1;

int gcd (int a,int b)
{
    return !b?a:gcd(b,a%b);
}

int lcm(int a, int b) {
    return (a/gcd(a,b))*b;
}

void go(int x, int c) {
    if (v[x] != 0 && c != 0) {
        if (c%2 == 0) {
            c = c/2;
        }
        if (ans == -1) {
            ans = c;
        } else {
            ans = lcm(ans, c);
        }
        return ;
    }
    v[x] = 1;
    go(a[x], c+1);
}

int main() {
    cin >> n;
    memset(in, 0, sizeof(in));
    memset(v, 0, sizeof(v));
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        in[a[i]]++;
    }
    for (int i=1; i<=n; i++) {
        if (in[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i=1; i<=n; i++) {
        go(i, 0);
    }
    cout << ans << endl;
}
