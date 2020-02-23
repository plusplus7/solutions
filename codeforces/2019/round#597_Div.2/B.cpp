#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, r, p, s;
        int rb = 0, pb = 0, sb = 0;
        char bob[105];
        cin >> n;
        cin >> r >> p >> s;
        cin >> bob;
        for (int i=0; bob[i]; i++) {
            if (bob[i] == 'S') sb++;
            else if (bob[i] == 'P') pb++;
            else rb++;
        }
        int flag = 0, wr, wp, ws;
        for (int i=0; i<=r && i<=sb; i++) {
            for (int j=0; j<=p && j<=rb; j++) {
                for (int k=0; k<=s && k<=pb; k++) {
                    if (i +j+k >= (n+1)/2 ) {
                            flag = 1;
                            wr = i;
                            wp = j;
                            ws = k;
                    }
                }
            }
        }
        if (flag == 1) {
            int twr = wr, twp = wp, tws = ws;
            cout <<"YES" << endl;
            char ans[105];
            for (int i=0; bob[i]; i++) {
                if (bob[i] == 'R' && twp > 0) {
                    ans[i] = 'P';
                    twp--;
                    continue;
                }
                if (bob[i] == 'P' && tws > 0) {
                    ans[i] = 'S';
                    tws--;
                    continue;
                }
                if (bob[i] == 'S' && twr > 0) {
                    ans[i] = 'R';
                    twr--;
                    continue;
                }
                ans[i] = 'X';
            }
            ans[n] = '\0';
            int ep = p-wp;
            int es = s-ws;
            int er = r-wr;
            for (int i=0; ans[i]; i++) {
                if (ans[i] == 'X') {
                    if (ep >0) {
                        ans[i] = 'P';
                        ep--;
                    } else if (er >0) {
                        ans[i] = 'R';
                        er--;
                    } else {
                        ans[i] = 'S';
                        es--;
                    }
                }
            }
            cout << ans<< endl;
        } else {
            cout << "NO" <<endl;
        }
    }
}
