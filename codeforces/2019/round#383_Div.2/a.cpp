#include <iostream>
using namespace std;

int main() {
    int n;
    int a[] = {8, 4, 2, 6};
    cin >> n;
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    n--;
    cout << a[n%4] << endl;
    return 0;
}
