#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
        int dish[6][7][3] = {{
            {1, 0, 0}, {0, 1, 0},{0, 0, 1},
            {1, 1, 0}, {1, 0, 1},{0, 1, 1},
            {1, 1, 1}
        }, {
            {1, 0, 0}, {0, 1, 0}, {0, 0, 1},
            {1, 1, 0}, {0, 1, 1}, {1, 0, 1},
            {1, 1, 1}
        }, {
            {1, 0, 0}, {0, 1, 0},{0, 0, 1},
            {1, 0, 1}, {0, 1, 1},{1, 1, 0},
            {1, 1, 1}
        }, {
            {1, 0, 0}, {0, 1, 0},{0, 0, 1},
            {1, 0, 1},{1, 1, 0}, {0, 1, 1},
            {1, 1, 1}
        }, {
            {1, 0, 0}, {0, 1, 0},{0, 0, 1},
            {0, 1, 1}, {1, 0, 1},{1, 1, 0}, 
            {1, 1, 1}
        }, {
            {1, 0, 0}, {0, 1, 0},{0, 0, 1},
            {0, 1, 1}, {1, 1, 0},{1, 0, 1}, 
            {1, 1, 1}
        }
        };
    scanf("%d", &T);
    while (T--) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        int ans =0;
        for (int m=0; m<6; m++) {
            int tans = 0;
            int ta = a, tb = b, tc = c;
            for (int i = 0; i < 7; i++)
            {
                if (ta >= dish[m][i][0] && tb >= dish[m][i][1] && tc >= dish[m][i][2])
                {
                    tans++;
                    ta -= dish[m][i][0];
                    tb -= dish[m][i][1];
                    tc -= dish[m][i][2];
                }
            }
            ans = tans > ans ? tans: ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}