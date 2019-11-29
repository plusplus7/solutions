#include<bits/stdc++.h>

using namespace std;

bool check(int a, int b) {
    int k = b-a;
    if ((a + (2 * k)) % 3 == 0)
    {
        int x1 = (a+(2*k))/3;
        if (x1-k < 0){
            return false;
        }
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    while (n--){
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            cout << "YES" << endl;
            continue;
        }

        if (a > b && check(b, a)) {
            cout << "YES" << endl;
        } else if (a <= b && check(a, b)) {
            cout << "YES" << endl;
        } else {
            cout <<"NO" << endl;
        }
    }
    return 0;
}
