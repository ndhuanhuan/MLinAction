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
	    if (head==NULL || head->next==NULL) return head;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		while (dummy->next) 
		{
		    auto tmp = dummy->next->next;
		    auto tmp2 =dummy->next;
			dummy->next->next = dummy;
			dummy->next = tmp;
			dummy = tmp2;
		}
		head->next = NULL;
		return dummy->next;
	}
};