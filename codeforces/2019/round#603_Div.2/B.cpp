#include <bits/stdc++.h>

using namespace std;

int a[10000], pr[10000];

int choose(int v) {
    int res = v;
    while (res == v) {

    int l[4] = {1, 10, 100, 1000};
    int r1 = rand()%4;
    int vl = (v/l[r1])%10;

    res = v - (vl * l[r1]) + ((vl + rand() % 10) % 10) * l[r1];
    }

    return res ;
}
int anss[10];
int main()
{
    int T;
    cin >> T;
    while (T--) {
        srand(77);
        int b[10];
        int n;
        int ans = 0;
        cin >> n;
        memset(a, -1, sizeof(a));

        for (int i=0; i<n; i++) {
            cin >> b[i];
            if (a[b[i]] == -1) {
                a[b[i]] = 0;
                anss[i] = b[i];
            } else {
                if (a[b[i]] == 0) {
                    ans += 1;
                    while (true) {

                        int t = choose(b[i]);
                        if (a[t] == -1) {
                            a[t] = 1;
                            pr[t] = i;
                            anss[i] = t;
                            break;
                        }
                    }
                } else {
                    a[b[i]] = 0;
                    int tk = pr[b[i]];
                    while (true){
                        int t = choose(b[tk]);
                        if (a[t] == -1) {
                            a[t] = 1;
                            pr[t] = tk;
                            anss[tk] = t;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        for (int i=0; i<n; i++) {
            printf("%04d\n", anss[i]);
        }
    }
}
