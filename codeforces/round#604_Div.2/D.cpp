#include <bits/stdc++.h>

using namespace std;

int no(){
    cout <<"NO" <<endl;
    return 0;
}
int main()
{
    int a, b, c, d;
    cin >> a >> b>> c>>d;

    if (a > b+1 || a+1 < b) {
        return no();
    }
    int aba = a > b ? a-b : 0;
    int bab = a < b ? b-a : 0;
    int ab = min(a,b);

    if (c > d+1 || c+1 < d) {
        return no();
    }
    int dcd = d > c ? d-c : 0;
    int cdc = d < c ? c-d : 0;
    int cd = min(c,d);

    int babdcd = min(dcd, bab)
}
