//http://bangbingsyb.blogspot.com/2014/11/leetcode-decode-ways.html
//http://coderuo.blogspot.com/2013/04/leetcode-decode-ways-in-c.html
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



//http://www.cnblogs.com/TenosDoIt/p/3451920.html
class Solution {
public:
    int numDecodings(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //注意处理字符串中字符为0的情况
        int len = s.size();
        if(len == 0)return 0;
        int dp[len+1];//dp[i]表示s[0...i-1]的解码方法数目
        dp[0] = 1;
        if(s[0] != '0')dp[1] = 1;
        else dp[1] = 0;
        for(int i = 2; i <= len; i++)
        {
            if(s[i-1] != '0')
                dp[i] = dp[i-1];
            else dp[i] = 0;
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))
                dp[i] += dp[i-2];
        }
        return dp[len];
    }
};

//比如112045 当 i=4时候代表1120 有多少种解法， 相当于11+20的解法加上112+0的解法，由于0无法解析成字母所以112+0
//11+20就是dp[i-2], 112+0 就是dp[i-1]. 所以说，加不加dp[i-1]取决于s[i-1]是否为0.


class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()||s[0]<'1'||s[0]>'9')
        {
            return 0;
        }
        vector<int> dp(s.size()+1,0);
        dp[0] = 1,dp[1]=1;
        for(int i=2; i<=s.size(); i++)
        {
            if(s[i-1]!='0')
                dp[i] = dp[i-1];
            else
                dp[i] = 0;
            int v = (s[i-2]-'0')*10+(s[i-1]-'0');
            if(v<=26&&v>9)
            {
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};
