#include <bits/stdc++.h>

using namespace std;

int n,k;
char c[200005];

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", c);
    string a(c), b;
    string ak = a.substr(0, k);

    if (k <= n/2) {
        string b = "";
        while (b.length() < n){
            b += ak;
        }
        b = b.substr(0, n);
        if (b >= a) {
            printf("%d\n", b.length());
            printf("%s\n", b.c_str());
        } else {
            int lak = ak.length()-1;
            while (ak[lak] == '9') {
                ak[lak] = '0';
                lak--;
            }
            ak[lak] ++;
            b = "";
            while (b.length() < n)
            {
                b += ak;
            }
            b = b.substr(0, n);
        printf("%d\n", b.length());
            printf("%s\n", b.c_str());
        }
    } else {
        ak = a.substr(0, n-k);
        int lx = n - (n-k)*2;
        string ax = a.substr(n-k, lx);
        b = ak + ax +ak;
        if (b >= a) {
                printf("%d\n", b.length());
            printf("%s\n", b.c_str());
        } else {
            int nines = 0;
            for (int i=0; i<ax.length(); i++) {
                if (ax[i] != '9') {
                    nines = 1;
                    break;
                }
            }
            if (nines == 0) {
                int lak = ak.length() - 1;
                while (ak[lak] == '9')
                {
                    ak[lak] = '0';
                    lak--;
                }
                ak[lak] ++;
                for (int i=0; i<ax.length(); i++) {
                    ax[i] = '0';
                }
                b = ak + ax+ak;
        printf("%d\n", b.length());
                printf("%s\n", b.c_str());
            } else {
                int lax = ax.length() - 1;
                while (ax[lax] == '9')
                {
                    ax[lax] = '0';
                    lax--;
                }

                ax[lax] ++;
                b = ak + ax + ak;
                printf("%d\n", b.length());
                printf("%s\n", b.c_str());
            }
        }
    }
}
