#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
char s[100005];
long long fib[100005];
void getfib()
{
    fib[0] = 1;
    fib[1] = 1;
    for (int i=2; i<100005; i++) {
        fib[i] = (fib[i-1] + fib[i-2])%MOD;
    }
}

int main()
{
    getfib();
    cin >> s;
    long long ans = 1ll;
    for (int i=0; s[i]; i++) {
        if (s[i] == 'w' || s[i] == 'm'){
            cout << 0 << endl;
            return 0;
        }
    }

    for (int i=0; s[i] != '\0';) {

        if (s[i] == 'u' || s[i] == 'n') {
           long long c = 0;
           char cc = s[i];
           while (s[i] != '\0' && s[i] == cc) {
                c++;
                i++;
           }

           ans *= fib[c];
           ans %= MOD;
        } else {
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
