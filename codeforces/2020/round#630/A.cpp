#include <bits/stdc++.h >
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b,c,d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int x,y,x1,x2,y1,y2;
        scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
        int ab = abs(a-b);
        if (a == b && a == 0) {

        } else {
            if (a > b) {
                if (x-ab < x1) {
                    cout <<"No" << endl;
                    continue;
                }
            } else {
                if (a == b && x == x1 && x == x2) {
                    cout <<"No" << endl;
                    continue;
                }
                if (x+ab > x2) {
                    cout <<"No" << endl;
                    continue;
                }
            }
        }
        int cd = abs(c-d);
        if (c == d && c == 0) {

        } else {
            if (c > d){
                if (y-cd < y1) {
                    cout <<"No" << endl;
                    continue;
                }
            } else {
                 if (c == d && y == y1 && y == y2) {
                    cout <<"No" << endl;
                    continue;
                }
                if (y+cd > y2) {
                    cout <<"No" << endl;
                    continue;
                }
            }
        }
        cout << "Yes" << endl;
    }
    return 0;
}
