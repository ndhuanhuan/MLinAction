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
	string convertToTitle(int n) {
		string ret;
		while (n>0) {
			char ch = 'A' + (n - 1) % 26;
			ret.insert(ret.begin(), ch);
			n -= (n - 1) % 26;
			n /= 26;
		}
		return ret;
	}
};
int main()
{
	Solution sol;
	//vector<int> nums{ 0,1,2,3,4,5,6 };
	cout<<sol.convertToTitle(28)<<endl;
	
	return 0;
	
			 

}
