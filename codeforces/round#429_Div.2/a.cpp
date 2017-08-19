#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, b[30];
    char c[1000];
    cin >> n >> k;
    cin >> c;
    memset(b, 0, sizeof(b));
    for (int i=0; c[i] != '\0'; i++) {
        b[c[i]-'a'] ++;
    }
    for (int i=0; i<26; i++) {
        if (b[i] > k) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
