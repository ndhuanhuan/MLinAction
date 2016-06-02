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
	int addDigits(int num) {
		while (num > 9) {
			num = num / 10 + num % 10;
		}
		return num;
	}
};
int main()
{
	Solution solution;
	//vector<int> nums = { 0,1, 2, 3,5, 6, 7, 8, 9 };
	int num = 38;
	std::cout << solution.addDigits(num) << endl;
	return 0;

}


//tricky
int addDigits03(int num) {
            return num >9 ? ((num %9)==0 ? 9:num%9) : num;
        }
