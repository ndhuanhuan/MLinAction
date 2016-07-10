// Leetcode.cpp : Defines the entry point for the console application.
//http://www.cnblogs.com/grandyang/p/4383632.html
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:
	int rob(vector<int> &num) {
		if (num.size() <= 1) return num.empty() ? 0 : num[0];
		vector<int> dp = { num[0], max(num[0], num[1]) };
		for (int i = 2; i < num.size(); ++i) {
			dp.push_back(max(num[i] + dp[i - 2], dp[i - 1]));
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
	
			 

}
