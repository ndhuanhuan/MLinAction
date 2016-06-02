// Leetcode.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//http://www.cnblogs.com/grandyang/p/4756677.html


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int total = 0;
		for (auto a : nums)
		{
			total += a;
		}
		int size = nums.size();
		return size*(size + 1) / 2 - total;

	}
};
int main()
{
	Solution solution;
	vector<int> nums = { 1, 2, 4, 5, 6, 7, 8, 9 };
	std::cout << solution.missingNumber(nums) << endl;
	return 0;

}
