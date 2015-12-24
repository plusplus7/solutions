#include <iostream>
#include <cstring>

using namespace std;

int v[507][507];
char op[100007];
int main()
{
    int x, y, x0, y0;
    memset(v, 0, sizeof(v));
    cin >> x >> y >> x0 >> y0;
    cin >> op;

    for (int i=0; op[i]; i++) {
        if (v[x0][y0]) {
            cout << "0 ";
        } else {
            cout << "1 ";
        }
        v[x0][y0] = 1;
        if (op[i] == 'U') {
            x0 -= (x0==1)?0:1;
        } else if (op[i] == 'D') {
            x0 += (x0==x)?0:1;
        } else if (op[i] == 'L') {
            y0 -= (y0==1)?0:1;
        } else {
            y0 += (y0==y)?0:1;
        }
    }
    int cnt = 0;
    for (int i=1; i<=x; i++) {
        for (int j=1; j<=y; j++) {
            cnt += 1-v[i][j];
        }
    }
    cout << cnt << endl;
}
