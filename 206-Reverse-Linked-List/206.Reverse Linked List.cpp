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
	ListNode* reverseList(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		dummy = dummy->next;
		while (dummy->next) 
		{
			dummy->next->next = dummy;
			dummy = dummy->next;
		}
		head->next = NULL;
		return dummy
	}
};