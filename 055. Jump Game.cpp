http://bangbingsyb.blogspot.com/2014/11/leetcode-jump-game-i-ii.html
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex =0;
        for(int i=0;i<n;i++)
        {
            if(i>maxIndex||maxIndex>=(n-1)) break;
            maxIndex = max(maxIndex,i+nums[i]);
        }
        return maxIndex>=(n-1)? true:false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v1{2,3,1,1,4};
    vector<int> v2{3,2,1,0,4};
    cout<<sol.canJump(v1)<<endl;
    cout<<sol.canJump(v2)<<endl;
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
