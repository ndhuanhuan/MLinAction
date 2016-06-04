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


class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		for (; n > 0; n /=2) 
		{
			if (n & 0x1)
				count++;
		}
		return count;
	}
};
int main()
{
	Solution sol;
	cout << sol.hammingWeight(0x110101);
	return 0;
	
			 

}
