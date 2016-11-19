class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n<=0) return 0;
        int maxSum = nums[0], curSum = nums[0];
        for(int i=1; i<n; i++) {
            curSum =  curSum<=0 ? nums[i] : nums[i]+curSum;
            maxSum = max(maxSum,curSum);
        }
        return maxSum;
    }
};


//dp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n,INT_MIN);
        dp[0] = nums[0];
        int res = dp[0];
        
        for(int i=0;i<n;i++)
        {
            dp[i] = nums[i]+(dp[i-1]>0?dp[i-1]:0);
            res = max(res,dp[i]);
        }
        return res;
    }
};
