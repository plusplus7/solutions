#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        long long a, b;
        cin >> a>>b;
        long long nine = 0, k = 0;
        while (nine <= b) {
            k++;
            nine*=10;
            nine+=9;
        }
        k--;

        cout << a*k<<endl;

    }
}