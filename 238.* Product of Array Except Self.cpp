// Leetcode.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		if (nums.empty()) 
		{
			return {};
		}

		vector<int> left_product(nums.size());
		left_product[0] = 1;
		for (int i=1;i<nums.size();i++)
		{
			left_product[i] = left_product[i - 1] * nums[i-1];
		}
		int right_product = 1;
		for (int i = nums.size() - 2; i >= 0; i--) 
		{
			right_product *= nums[i + 1];
			left_product[i] = left_product[i] * right_product;
		}
		return left_product;
	}
};  
int main()
{
	Solution solution;
	vector<int> nums = { 1, 2, 3,5, 6, 7, 8, 9 };
	//int num = 38;
	//std::cout << solution.productExceptSelf(nums) << endl;
	for (int x : solution.productExceptSelf(nums))
		 std::cout << x << endl;
	return 0;

}
