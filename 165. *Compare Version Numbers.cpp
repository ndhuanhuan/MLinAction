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
	int compareVersion(string version1, string version2) {
		int n1 = version1.length();
		int n2 = version2.length();
		for (int i = 0, j = 0; i < n1 || j < n2; ++i, ++j) 
		{
			int v1 = 0, v2 = 0;
			while (i < n1&&version1[i] != '.') 
			{
				v1 = v1 * 10 + version1[i] - '0';
				i++;
			}
			while (j < n2&&version2[j] != '.')
			{
				v2 = v2 * 10 + version2[j] - '0';
				j++;
			}

			if (v1 != v2) {
				return v1 > v2 ? 1 : -1;
			}
		}
		return 0;
	}
};
int main()
{
	Solution sol;
	//vector<int> nums{ 0,1,2,3,4,5,6 };
	cout<<sol.compareVersion("1.1","1.23")<<endl;
	
	return 0;
	
			 

}
