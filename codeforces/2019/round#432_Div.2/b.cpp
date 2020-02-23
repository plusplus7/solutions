
#include <bits/stdc++.h>
using namespace std;
struct point {
    double x;
    double y;
};
double mul(point a, point b, point c)
{
    a.x -= c.x;
    a.y -= c.y;
    b.x -= c.x;
    b.y -= c.y;
    return a.x * b.x + a.y * b.y;
}
double dist(point a, point b)
{
    return sqrt(mul(a, a, b));
}


double angle(point  a, point b, point c)
{
    return acos(mul(a, b, c) / dist(a, c) / dist(b, c));
}
point circumcenter(const point &a, const point &b, const point &c)
{
    point ret;
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 - a2 * b1;
    if (fabs(d - 0.0) < 1e-7) {
        cout << "No" << endl;
        exit(0);
    }
    ret.x = a.x + (c1 * b2 - c2 * b1) / d;
    ret.y = a.y + (a1 * c2 - a2 * c1) / d;
    return ret;
}

int main()
{
    point A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    point D = circumcenter(A, B, C);

    if (fabs(angle(A, B, D) - angle(B, C, D)) < 1e-7) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
