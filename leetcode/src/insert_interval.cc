#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        map<int, int> mp;
        map<int, int> pm;
        mp.clear();
        pm.clear();

        int lmp = 0;

        vector<int> asc;
        asc.clear();
        asc.push_back(newInterval.start);
        asc.push_back(newInterval.end);
        for (auto i : intervals) {
            asc.push_back(i.start);
            asc.push_back(i.end);
        }
        sort(asc.begin(), asc.end());

        for (auto i : asc) {
            if (mp.find(i) == mp.end()) {
                pm[lmp] = i;
                mp[i] = lmp++;
            }

            if (mp.find(i) == mp.end()) {
                pm[lmp] = i;
                mp[i] = lmp++;
            }
        }
        int *v = new int [lmp];
        bool *multi = new bool [lmp];

        for (int i=0; i<lmp; i++)
            v[i] = 0, multi[i] = false;;
        for (auto i : intervals) {
            if (i.start == i.end)
                multi[mp[i.start]] = true;
            v[mp[i.start]]++, v[mp[i.end]]--;
        }

        if (newInterval.start == newInterval.end)
            multi[mp[newInterval.start]] = true;
        v[mp[newInterval.start]]++, v[mp[newInterval.end]]--;


        vector<Interval> ans;
        ans.clear();
        int pr = -1, cnt = 0;
        for (int i=0; i<lmp; i++) {
            if (multi[i] == true)
                ans.push_back(Interval(pm[i], pm[i]));
            if (v[i] == 0)
                continue;
            if (pr == -1)
                pr = i;
            cnt = cnt+v[i];
            if (cnt == 0) {
                ans.push_back(Interval(pm[pr], pm[i]));
                pr = -1;
            }
        }
        return ans;
    }
};

int main() {
    vector<Interval> vv;
    vv.push_back(Interval(1,3));
    vv.push_back(Interval(5,9));

    vector<Interval> ans = Solution().insert(vv, Interval(2,7));
    for (auto i : ans)
        cout<<i.start<<" "<<i.end<<endl;
}
