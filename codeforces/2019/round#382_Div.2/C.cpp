#include <cstdio>
#include <iostream>
using namespace std;

long long solve(long long n) {

    if (n < 2) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n == 3) {
        return 2;
    }
    long long t = n%3;
    if (t == 1) {
        return solve(n/3) +2;
    } else if (t == 2) {
        return solve(n/3 + 1) + 2;
    } else {
        return solve(n/3) +2;
    }
}

int main() {
    long long n;
    cin >> n;
    cout << solve(n) <<endl;
    return 0;
}
