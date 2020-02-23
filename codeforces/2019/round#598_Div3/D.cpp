#include <bits/stdc++.h>

using namespace std;

char s[1000005];
int main()
{
    int q;
    cin >> q;
    while (q--) {
        long long n,k;
        cin >> n >> k >> s;
        long long done = 0, notdone = 0;
        for (int i=0; s[i] != '\0'; i++) {
            if (s[i] == '0') {
                if (k >= i-done) {
                    k -= i-done;
                    done++;
                } else {
                    notdone = i-k-done;
                    break;
                }
                if (k == 0) {
                    break;
                }
            }
        }

        for (int i=0; i<done; i++){
            cout << '0';
        }
        if (notdone != 0) {
            done++;
            for (int i=0; i<notdone; i++) {
                cout << '1';
            }
            cout << '0';
        }

        for (int i=0; s[i] != '\0'; i++) {
            if (s[i] == '0' && done > 0) {
                done--;
                continue;
            } else {
                if (s[i] == '1' && notdone > 0) {
                    notdone --;
                    continue;
                }
                cout << s[i];
            }
        }
        cout << endl;
    }
}
