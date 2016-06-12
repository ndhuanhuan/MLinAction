//http://bangbingsyb.blogspot.com/2014/11/leetcode-merge-k-sorted-lists.html





class Solution {
public:
	struct compNode 
	{
		bool operator()(ListNode* l1, ListNode* l2)  const
		{
			if (l1->val >= l2->val) 
			{
				return true;
			}
			else 
			{
				return false;
			}
		
		}
	};

	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode*, vector<ListNode*>, compNode> pq;
		ListNode *dummy = new ListNode(0), *tail = dummy;
		for (int i = 0; i < lists.size(); i++) 
		{
			if (lists[i]) 
			{
				pq.push(lists[i]);
			}
			
		}
		while (!pq.empty()) {
			tail->next = pq.top();
			tail = tail->next;
			pq.pop();
			if (tail->next) pq.push(tail->next);
		}
		return dummy->next;

	}
};









class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.empty()) return NULL;
		int end = lists.size() - 1;
		while (end>0) {
			int begin = 0;
			while (begin<end) {
				lists[begin] = merge2Lists(lists[begin], lists[end]);
				begin++;
				end--;
			}
		}
		return lists[0];
	}

	ListNode* merge2Lists(ListNode *h1, ListNode *h2) {
		ListNode *dummy = new ListNode(0), *tail = dummy;
		while (h1 && h2) {
			if (h1->val <= h2->val) {
				tail->next = h1;
				h1 = h1->next;
			}
			else {
				tail->next = h2;
				h2 = h2->next;
			}
			tail = tail->next;
		}
		tail->next = h1 ? h1 : h2;
		return dummy->next;
	}
};
