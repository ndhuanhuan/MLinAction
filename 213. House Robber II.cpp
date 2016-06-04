


// Leetcode.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
		else if (nums.size() == 2) return max(nums[0], nums[1]);
		else 
		{
			int m1 = original_rob(nums, 0, nums.size() - 1);
			int m2 = original_rob(nums, 1, nums.size());
			return max(m1, m2);
		}
	}


	int original_rob(vector<int> &nums, int left, int right) 
	{
		//if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
		vector<int> dp(right, 0);
		dp[left] = nums[left];
		dp[left + 1] = max(nums[left], nums[left + 1]);
		for (int i = left+2; i < right; ++i) {
			dp[i]=max(nums[i] + dp[i - 2], dp[i - 1]);
		}
		return dp.back();
	
	}

};
int main()
{
	Solution sol;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	cout << sol.rob(nums) << endl;;
	return 0;
	
			return 0;

}









//reuse House robbber I 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int simpleRob(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];
    for (int i = 2; i <= nums.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
    }
    return dp[nums.size()];
}

int rob(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
    if(nums.size() == 1)
        return nums[0];

    vector<int> case1(nums.begin(), nums.end()-1);
    vector<int> case2(nums.begin()+1, nums.end());

    return max(simpleRob(case1), simpleRob(case2));

}


int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    cout << rob(nums) << endl;;
    return 0;
}
