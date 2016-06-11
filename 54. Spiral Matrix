
https://github.com/soulmachine/leetcode

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
	vector<int> spiralOrder(vector<vector<int> >& matrix) {
		vector<int> result;
		if (matrix.empty()) return result;
		int beginX = 0, endX = matrix[0].size() - 1;
		int beginY = 0, endY = matrix.size() - 1;
		while (true) {
			// From left to right
			for (int j = beginX; j <= endX; ++j) result.push_back(matrix[beginY][j]);
			if (++beginY > endY) break;
			// From top to bottom
			for (int i = beginY; i <= endY; ++i) result.push_back(matrix[i][endX]);
			if (beginX > --endX) break;
			// From right to left
			for (int j = endX; j >= beginX; --j) result.push_back(matrix[endY][j]);
			if (beginY > --endY) break;
			// From bottom to top
			for (int i = endY; i >= beginY; --i) result.push_back(matrix[i][beginX]);
			if (++beginX > endX) break;
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > matrix = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 },{ 10, 11, 12 } };
	//vector<int> nums{ 0,1,2,3,4,5,6 };
	//cout<<sol.compareVersion("1.1","1.23")<<endl;
	vector<int> ret = s.spiralOrder(matrix);
	for (auto i : ret) 
	{
		cout << i << endl;
	}

	return 0;
	
			 

}
