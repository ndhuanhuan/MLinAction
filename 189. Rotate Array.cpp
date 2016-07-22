// Leetcode.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//	
//};

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if((k<=0)||(n==0)) return;
        k %= n;
        reverse2(nums,0,n-1);
        reverse2(nums,0,k-1);
        reverse2(nums,k,n-1);
    }
    
    void reverse2(vector<int>& nums, int start, int end)
    {
        int temp;
		while (start < end)
		{
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
			start++;
			end--;
		}
    }
};
int main()
{
	Solution sol;
	vector<int> nums{ 0,1,2,3,4,5,6 };
	sol.rotate(nums, 3);
	for (auto i : nums)
		cout << i << endl;
	return 0;
	
			 

}
