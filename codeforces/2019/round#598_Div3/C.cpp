#include <bits/stdc++.h>

using namespace std;

int main()
{


        int n, m, d, c[1005], s =0;
        int ans[1005];
        memset(ans, 0, sizeof(ans));
        cin >> n>> m>> d;
        for (int i=1; i<=m; i++) {
            cin >> c[i];
            s+=c[i];
        }

        int cur = 0, tc = 1;
        while (1) {
            if (cur + d < n+1 - s) {
                if (s == 0) {
                    cout << "NO" << endl;
                    return 0;
                }
                for (int i=cur+d; i<cur+d+c[tc]; i++) {

                    ans[i] = tc;

                }
                cur = cur+d+c[tc]-1;
                s -= c[tc];
                tc++;
            } else {
                break;
            }
        }cout << "YES" << endl;
        if(s != 0){
            int j = n;
            for (int i=m; i>=tc; i--) {
                for (int k =0; k<c[i]; k++, j--) {
                    ans [j] = i;
                }

            }
        }

        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;

}
