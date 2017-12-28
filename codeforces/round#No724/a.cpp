#include <iostream>

using namespace std;

int solve(int t1, int t2) {
    int c = 0, ans = 0;
    while (t1 != 0 || t2 != 0) {
        int l1 = t1%10, l2 = t2%10;
        if (l1 + l2 + c >= 10) {
            ans ++;
        }
        c = (l1+l2+c)/10;
        t1/=10;
        t2/=10;
    }
    return ans;
}

int main() {
    int t1, t2;
    while (true) {
        cin >> t1 >> t2;
        if (t1 == 0 && t2 == 0) {
            break;
        }
        int ans = solve(t1, t2);
        if (ans == 0) {
            cout << "No carry operation." << endl;
        } else {
            cout << ans << " " << "carry operation" << (ans <= 1 ? "." : "s.") << endl; 
        }
    }
    return 0;
}
