#include <iostream>
#include <string>
using namespace std;

char a[1000060];
int main() {
    int n;
    string s;
    cin >> n;
    cin>>s;
    int t1=0, t2=0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'A') {
            t1++;
        } else {
            t2++;
        }
    }
    if (t1 > t2) {
        cout << "Anton" << endl;
    } else if (t2 > t1) {
        cout << "Danik" << endl;
    } else {
        cout << "Friendship" << endl;
    }
    return 0;
}

