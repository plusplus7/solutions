#include <bits/stdc++.h>

using namespace std;
int n;
struct Node {
    int s;
    int c;
};
vector<Node> vn;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        vn.clear();
        scanf("%d", &n);
        int g = 0, s = 0, b = 0, lm = n/2;
        Node pr;
        for (int i=0; i<n; i++) {
            int t;
            scanf("%d", &t);
            if (i == 0){
                pr.s = t;
                pr.c = 1;
            } else {
                if (pr.s != t) {
                    vn.push_back(pr);
                    pr.s = t;
                    pr.c = 1;
                } else {
                    pr.c++;
                }
            }
        }
        if (vn.size() < 3) {
            printf("0 0 0\n");
            continue;
        }
        g = vn[0].c;
        int ts = 0, tb = 0;
        for (int i=1; i<vn.size(); i++) {
            if (s == 0) {
                ts += vn[i].c;
                if (ts > g) {
                    s = ts;
                }
            } else {
                tb += vn[i].c;
                if (g + s + tb > lm) {
                    break;
                } else {
                    b = tb;
                }
            }
        }

        if (b == 0 || s == 0 || b <= g) {
            printf("0 0 0\n");
        } else {
            printf("%d %d %d\n", g, s ,b);
        }
    }
}
