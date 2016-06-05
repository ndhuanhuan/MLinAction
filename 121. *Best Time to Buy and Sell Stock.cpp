//
http://bangbingsyb.blogspot.com/2014/11/leetcode-best-time-to-buy-and-sell.html

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
            if(prices.size()==0) return 0;
            int minValue = prices[0],ret = 0;
            for(int i=0;i<prices.size();i++)
            {
                if(prices[i]<minValue)
                {
                    minValue = prices[i];
                }
                else
                    ret = max(prices[i]-minValue,ret);
            }
            return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s  ="bcdedcb";
    vector<int> v{4,5,6,15,0,1,2};

    cout << sol.maxProfit(v) << endl;
//    cout << sol.findKthLargest(v, 2) << endl;
//    cout << sol.findKthLargest(v, 3) << endl;
//    cout << sol.findKthLargest(v, 4) << endl;
//    cout << sol.findKthLargest(v, 5) << endl;
//    cout << sol.findKthLargest(v, 6) << endl;

    return 0;
}
