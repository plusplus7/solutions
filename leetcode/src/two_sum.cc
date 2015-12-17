#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ans;
            ans.clear();
            for (int i=0; i<nums.size(); i++) {
                for (int j=i+1; j<nums.size(); j++) {
                    if (target == nums[i] + nums[j]) {
                        ans.push_back(i+1);
                        ans.push_back(j+1);
                        return ans;
                    }
                }
            }
            return ans;
        }
};

int main()
{
return 0;
}
