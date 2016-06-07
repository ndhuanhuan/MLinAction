//http://bangbingsyb.blogspot.com/2014/11/leetcode-decode-ways.html

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



 //Definition for singly-linked list with a random pointer.
// struct RandomListNode {
//     int label;
//    RandomListNode *next, *random;
//     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
// };

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()||s[0]<'1'||s[0]>'9') return 0;
        vector<int> dp(s.size()+1,0);
        dp[0] =dp[1]=1;
        for(int i=1;i<s.size();i++)
        {
            if(!isdigit(s[i])) return 0;
            int v=(s[i-1]-'0')*10+(s[i]-'0');
            if(v<=26&&v>9) dp[i+1] += dp[i-1];
            if(s[i]!='0') dp[i+1] += dp[i];
            if(dp[i+1]==0) return 0;
        }

         return dp[s.size()];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout<<sol.numDecodings("1234567")<<endl;
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
