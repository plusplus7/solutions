#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[3];
    int t;
    for (int i=0; i<3; i++) {
        cin >> a[i];
    }
    for (int i=0; i<3; i++) {
        cin >> t;
        a[i] = a[i]-t;
    }

    sort(a, a+3);
    for (int i=0, l=2; i<3; i++) {
        if (a[i] >= 0) {
            break;
        }
        while (a[i] < 0 && i < l && a[l] >= 2) {
            a[l]-=2;
            a[i]++;
            if (a[l] < 2) {
                l--;
            }
        }
        if (a[i] < 0) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}

