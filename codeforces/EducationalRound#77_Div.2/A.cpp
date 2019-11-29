#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--){
        long long ans = 0ll ,c,s;
        cin >> c >> s;
        long long t = s%c, x = s/c;

        for (int i=0; i<c; i++) {
            if (t != 0) {
                t--;
                ans += (x+1)*(x+1);
            }
            else {
                ans += x*x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}