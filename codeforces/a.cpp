#include <iostream>
#include <string>
using namespace std;

int no(string a) {
    if (a[0] == 'm') {
        return 0;
    }
    if (a[0] == 't' && a[1] == 'u') {
        return 1;
    }
    if (a[0] == 'w') {
        return 2;
    }
    if (a[0] == 't' && a[1] == 'h') {
        return 3;
    }
    if (a[0] == 'f') {
        return 4;
    }
    if (a[0] == 's' && a[1] == 'a') {
        return 5;
    }
    if (a[0] == 's' && a[1] == 'u') {
        return 6;
    }
    return 9999;
}

int main() {
    string a, b;
    cin >> a >> b;
    int ia = no(a);
    int ib = no(b);
    if (ia  == ib || (ia + 2)%7 == ib || (ia + 3) % 7 == ib) {
        cout << "YES" << endl;;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
