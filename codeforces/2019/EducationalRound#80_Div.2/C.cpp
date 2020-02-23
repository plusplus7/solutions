#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
int mem1[1005][15];
int mem2[1005][15];

int gao1(int n, int m)
{
    if (m == 0) {
        return 1;
    }

    if (m == 1) {
        return n;
    }

    if (mem1[n][m] != -1) {
        return mem1[n][m];
    }

    int res = 0;
    res += gao1(n, m - 1) % MOD;
    for (int i=1; i<n; i++) {
        res = (res + gao1(i, m-1)) % MOD;
    }
    mem1[n][m] = res;
    return res;
}

int gao2(int l, int n, int m)
{
    //cout << l << "-"<< n << "-" << m<<endl;
    if (m == 0) {
        return 1;
    }

    if (m == 1) {
        return l-n+1;
    }

    if (mem2[n][m] != -1) {
        return mem2[n][m];
    }

    int res = 0;
    res = gao2(l, n, m - 1) % MOD;
    for (int i=n+1; i<=l; i++) {
        res = (res + gao2(l, i, m-1)) % MOD;
    }
    mem2[n][m] = res % MOD;
    return res;
}
int main()
{
    int n,m;
    cin >>n>>m;
    memset(mem1, -1, sizeof(mem1));
    memset(mem2, -1, sizeof(mem2));
  //  gao1(1000, 10);
  //  gao2(n, 1000, 10);
    long long ans = 0ll;
    for (int i=1; i<=n; i++) {
        int am = i;
        long long x1 = gao1(am, m-1);
        long long x2 = gao2(n, am, m);
    //    cout << am << " " << x1 << " " << x2 << endl;
        ans = (ans + (x1*x2)%MOD ) %MOD;

    }
    cout << ans <<endl;
    return 0;
}
