// Leetcode.cpp : Defines the entry point for the console application.
//http://yucoding.blogspot.com/2015/06/leetcode-question-reverse-linked-list.html
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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		//ListNode* dummy = new ListNode(0);
		//dummy->next = head;
		ListNode *h = NULL, *p = NULL;
		while (head)
		{
			p = head->next;
			head->next = h;
			h = head;
			head = p;
		}
		return h;
	}
};
int main()
{
	Solution sol;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	ListNode* res;
	res = sol.reverseList(&n1);
	while (res != NULL) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
	return 0;
	
			 

}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * newhead = new ListNode(0);
        while (head){
            ListNode * tmp = newhead->next;
            newhead->next = head;
            head = head->next;
            newhead->next->next = tmp;
        }
        return newhead->next;
         
    }
};
