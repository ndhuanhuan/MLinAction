//http://yucoding.blogspot.com/2014/12/leetcode-question-intersection-of-two.html
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
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int length1 = 0;
		int length2 = 0;
		ListNode* a1 = headA;
		ListNode* a2 = headB;

		while (a1) 
		{
			length1++;
			a1 = a1->next;
		}
		while (a2) 
		{
			length2++;
			a2 = a2->next;
		}

		a1 = headA;
		a2 = headB;

		while (length1 > 0 && length2 > 0) 
		{
			if (length1>length2) 
			{
				length1--;
				a1 = a1->next;
			}
			if (length2 > length1)
			{
				length2--;
				a2 = a2->next;
			}
			if(length1 == length2)
			{
				if (a1 == a2) 
				{
					return a1;
				}
				else 
				{
					a1 = a1->next;
					a2 = a2->next;
					length1--;
					length2--;
				}
			}
		}

		return NULL;

	}
};
int main()
{
	Solution s;
	//vector<int> nums{ 0,1,2,3,4,5,6 };
	//cout<<sol.compareVersion("1.1","1.23")<<endl;
	ListNode *list[10];
	for (int i = 0; i < 8; ++i) {
		list[i] = new ListNode(i);
	}
	list[0]->next = list[1];
	list[1]->next = list[2];
	list[3]->next = list[4];
	list[4]->next = list[5];
	list[5]->next = list[2];
	list[2]->next = list[6];
	list[6]->next = list[7];
	
	ListNode *inter = s.getIntersectionNode(list[0], list[3]);
	cout << inter->val << endl;
	return 0;
	
			 

}
