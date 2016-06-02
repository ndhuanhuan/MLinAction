
//api不熟
//http://www.cnblogs.com/grandyang/p/4938187.html
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (const auto& num : nums) {
            insert(&LIS, num);
        }

        return LIS.size();
    }

private:
    void insert(vector<int> *LIS, const int target) {
        // Find the first index "left" which satisfies LIS[left] >= target
        auto it = lower_bound(LIS->begin(), LIS->end(), target);

        // If not found, append the target.
        if (it == LIS->end()) {
            LIS->emplace_back(target);
        } else {
            *it = target;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout<<solution.lengthOfLIS(nums)<<endl;
    return 0;
    
}
