/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
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