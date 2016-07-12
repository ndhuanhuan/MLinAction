//curr->next->random = curr->random->next;
//https://yanjianwei.gitbooks.io/algorithm-reading/content/linked_list/copy_list_with_random_pointer.html

|--------------------------|
|                          v
1  --> 1' --> 2 --> 2' --> 3 --> 3' --> 4 --> 4'
       |                   ^
       |-------------------|
       

|--------------------------|
|                          v
1  --> 1' --> 2 --> 2' --> 3 --> 3' --> 4 --> 4'
       |                         ^
       |-------------------------|


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for(auto *curr=head;curr;curr=curr->next->next)
        {
            auto *node = new RandomListNode(curr->label);
            node->next = curr->next;
            curr->next = node;
        }

        for(auto *curr=head; curr;curr = curr->next->next)
        {
            if(curr->random)
            {
                curr->next->random = curr->random->next;  //cur->random->next is the random node that you copied
            }
        }

        RandomListNode dummy(0);
        for(auto *curr=head,*copy_curr=&dummy; curr;copy_curr=copy_curr->next,curr=curr->next)
        {
            copy_curr->next = curr->next;
            curr->next = curr->next->next;
        }
        return dummy.next;
    }
};
