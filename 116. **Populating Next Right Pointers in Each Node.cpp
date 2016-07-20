//http://blog.csdn.net/kenden23/article/details/18361993

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


 struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root)
        {
            TreeLinkNode* next = NULL, *prev=NULL; //reset each time go to next level
            for(;root;root=root->next)
            {
                if(!next)
                    next = root->left?root->left:root->right;
                    if(root->left)
                    {
                        if(prev) prev->next = root->left;
                        prev = root->left;
                    }
                    if(root->right)
                    {
                        if(prev) prev->next = root->right;
                        prev = root->right;
                    }



            }

            root=next;

        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    //string s  ="bcdedcb";
    //vector<int> v{4,5,6,15,0,1,2};

    //cout << sol.maxProfit(v) << endl;
//    cout << sol.findKthLargest(v, 2) << endl;
//    cout << sol.findKthLargest(v, 3) << endl;
//    cout << sol.findKthLargest(v, 4) << endl;
//    cout << sol.findKthLargest(v, 5) << endl;
//    cout << sol.findKthLargest(v, 6) << endl;

    return 0;
}
