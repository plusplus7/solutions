#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::map;
using std::endl;
using std::string;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.length() == 0) {
                return 0;
            }
            int ans = 1;
            int si = 0, e = 0;
            map<int, int> mp;
            mp.clear();
            for (int i=0; i<s.length(); i++) {
                int id = int(s[i]-'a'); 
                if (mp.count(id) == 0) {
                    mp[id] = i;
                    e++;
                } else {
                    if (mp[id] == -1) {
                        e++;
                    } else {
                        ans = ans > e-si ? ans : e-si;
                        for (int j=si; j<=mp[id]; j++) {
                            mp[int(s[j]-'a')] = -1;
                        }
                        si = mp[id]+1;
                    }
                }
            }
            ans = ans > e-si ? ans : e-si;
            cout << e << " " << si << endl;
            return ans;
        }
};

int main()
{
    string s = "abcabcbb";
    cout << Solution().lengthOfLongestSubstring(s);
    cout << Solution().lengthOfLongestSubstring("");
    cout << Solution().lengthOfLongestSubstring("bbbbbb");
}
