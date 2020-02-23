#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n, k, li = 0;
    char in[1000], tin[1000];
    int c[1000];
    cin >> n >> k;
    cin >> tin;
    int f = 0;
    for (int i=0; i<n; i++) {
        if (tin[i] == 'T' || tin[i] == 'G') {
            f++;
            in[li++] = tin[i];
            continue;
        }
        if (f == 1) {
            in[li++] = tin[i];
        }
    }
    in[li] = '\0';

    memset(c, -1, sizeof(c));
    c[0] = 1;
    for (int i=0; i<li; i++) {
        if (i-k >= 0) {
            if (in[i-k] != '#' && c[i-k] != -1) {
                c[i] = 1;
            }
        }
    }
    if (c[li-1] == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
