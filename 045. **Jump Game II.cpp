//http://bangbingsyb.blogspot.com/2014/11/leetcode-jump-game-i-ii.html
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curMax = 0, njumps = 0, i = 0;
        while(curMax<n-1) {
            int lastMax = curMax;
            for(; i<=lastMax; i++) 
                curMax = max(curMax,i+nums[i]);
            njumps++;
            if(lastMax == curMax) return -1;
        }
        return njumps;  
    }
};
