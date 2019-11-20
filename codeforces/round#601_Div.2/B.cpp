#include <bits/stdc++.h>
using namespace std;
struct fge {
    int no;
    int c;
};
fge a[10005];

bool cmp(fge a, fge b)
{
    return a.c < b.c;
}
int solve()
{
    int n,m;
    cin >>n >> m;
    long long s = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i].c;
        a[i].no = i;
        s += a[i].c*2ll;
    }
    if (m < n || n == 2) {
        cout << -1 << endl;
    } else {
        sort(a, a+n, cmp);
        m-=n;
        s += (a[1].c+a[2].c)*(long long)m;
        cout << s << endl;
        for (int i=1; i<n; i++) {
            cout << i << " " << i+1 << endl;
        }
        cout << n << " " << 1 << endl;
        while (m--) {
            cout << a[1].no << " " << a[2].no << endl;
        }
    }



}

int main()
{
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
