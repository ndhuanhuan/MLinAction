class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(-1);
		ListNode *p = &dummy;
		int carry = 0;
		ListNode *p1 = l1, *p2 = l2;
		while (p1!=nullptr || p2!=nullptr) 
		{
		    const int ai = p1 == nullptr ? 0 : p1->val;
            const int bi = p2 == nullptr ? 0 : p2->val;
			int tempVal =ai+bi+carry;
			if (tempVal >= 10) 
			{
				carry = 1;
				tempVal %= 10;
			}
			else 
			{
				carry = 0;
			}
			ListNode* tempNode = new ListNode(tempVal);
			p->next = tempNode;
			p1 = p1 == nullptr ? nullptr : p1->next,
            p2 = p2 == nullptr ? nullptr : p2->next,
			p = p->next;
		}
		if (carry > 0)
            p->next = new ListNode(carry);
		return dummy.next;
	}
};
