#include <bits/stdc++.h>
using namespace std;

int main() {

    int a,b,c,d,e,f;
    cin >> a>>b>>c>>d>>e>>f;
    int mf, me;
    if (f > e) {
        mf = min(min(b,c),d);
        d -= mf;
        me = min(d,a);
    } else {
        me = min(d, a);
        d -= me;
        mf = min(min(b,c),d);
    }
    printf("%d\n", me*e + mf*f);
}
