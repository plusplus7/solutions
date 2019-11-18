#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <iomanip>
#include <queue>
#define INF 0x7FFFFFFF

using namespace std;

struct point
{
    double x,y;
    point(){}
    point(double _x,double _y)
    {   x=_x;
        y=_y;
    }
};

#define interval point


vector<interval> intervals;
bool cmp(point a, point b) {
    return a.x < b.x;
}

int main()
{
    int n, d, T;
    double r;
    T = 1;
    while (cin >> n >> r) {
        if (n == 0) {
            break;
        }
        intervals.clear();

        int flag = 1;
        for (int i=0; i<n; i++) {
            int x, y;
            cin >> x >> y;

            if (y <= r) {
                intervals.push_back(point(x-sqrt(r*r-y*y), x+sqrt(r*r-y*y)));
            } else {
                flag = 0;
            }
        }
        if (flag == 0) {
            printf("Case %d: %d\n", T++, -1);
            continue;
        }
        sort(intervals.begin(), intervals.end(), cmp);

        double cr;
        int ans = 0;
        for (int i=0; i<intervals.size(); i++) {
            if (i == 0) {
                cr = intervals[i].y;
                ans++;
                continue;
            }
            if (intervals[i].x > cr) {
                cr = intervals[i].y;
                ans++;
            } else {
                if (intervals[i].y < cr) {
                    cr = intervals[i].y;
                }
            }
        }
        printf("Case %d: %d\n", T++, ans);
    }
}
